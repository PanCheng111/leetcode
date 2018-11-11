#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
private:
    const int maxp = 1000000007;
    int *power;
    int getHash(int *hash, int be, int ed) {
        return hash[ed] - hash[be] * power[ed - be];
    }

public:
    string longestPalindrome(string s) {
        int len = s.length();
        int *hash = (int *)calloc(sizeof(int), len + 1);
        int *rhash = (int *)calloc(sizeof(int), len + 1);
        power = (int *)calloc(sizeof(int), len + 1);
        power[0] = 1;
        for (int i = 0; i < len; i++) {
            hash[i + 1] = hash[i] * maxp + s[i];
            rhash[i + 1] = rhash[i] * maxp + s[len - i - 1];
            power[i + 1] = power[i] * maxp;
        }
        for (int i = len; i > 0; i--)
            for (int j = 0; j + i <= len; j++) {
                int v1 = getHash(hash, j, j + i);
                int v2 = getHash(rhash, len - (j+i), len - j);
                if (v1 == v2) {
                    return s.substr(j, i);
                }
            }
        return "";
    }
};

int main() {
    Solution s;
    printf("%s\n", s.longestPalindrome("").c_str());
    return 0;
}