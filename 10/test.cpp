#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    int **opt;

public:
    bool checkMatch(int i, int j, int l1, int l2, const string s, const string p) {
        if (j == l2) return i == l1;
        //if (i == l1) return j == l2;
        if (opt[i][j] != -1) return opt[i][j];
        bool ret = false;
        if (j < l2 - 1 && p[j + 1] == '*') {
            bool ret1 = false, ret2 = false;
            if (i < l1 && (s[i] == p[j] || p[j] == '.')) ret1 = checkMatch(i + 1, j, l1, l2, s, p);
            ret2 = checkMatch(i, j + 2, l1, l2, s, p);
            ret = ret1 || ret2;
        }
        else {
            if (i < l1 && (s[i] == p[j] || p[j] == '.')) ret = checkMatch(i + 1, j + 1, l1, l2, s, p);
            else ret = false;
        }
        opt[i][j] = ret;
        return ret;
    }

    bool isMatch(string s, string p) {        
        int len1 = s.length();
        int len2 = p.length();
        opt = new int*[len1 + 1];
        for (int i = 0; i <= len1; i++) {
            opt[i] = new int[len2 + 1];
            for (int j = 0; j <= len2; j++)
                opt[i][j] = -1;
        }
        return checkMatch(0, 0, len1, len2, s, p);
    }

};

int main() {
    Solution s;
    printf("%d\n", s.isMatch("aa", "a*"));
    return 0;
}