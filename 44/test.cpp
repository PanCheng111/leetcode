#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    int **opt;
public:

    bool check(int i, int j, int l1, int l2, const string &s, const string &p) {
        //if (i == l1) return (j == l2);
        if (j == l2) return (i == l1);
        if (opt[i][j] != -1) return opt[i][j];
        bool ret;
        if (p[j] == '?') ret = (i < l1) && check(i + 1, j + 1, l1, l2, s, p);
        else if (p[j] == '*') {
            bool t1 = (i < l1) && check(i + 1, j, l1, l2, s, p);
            bool t2 = check(i, j + 1, l1, l2, s, p);
            ret = t1 || t2;
        }
        else {
            if (i < l1 && s[i] == p[j]) ret = check(i + 1, j + 1, l1, l2, s, p);
            else ret = false;
        }
        opt[i][j] = ret;
        return ret;
    }

    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        opt = new int*[len1 + 1];
        for (int i = 0; i <= len1; i ++) {
            opt[i] = new int[len2 + 1];
            for (int j = 0; j <= len2; j++)
                opt[i][j] = -1;
        }
        return (check(0, 0, len1, len2, s, p));
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isMatch("acdcb", "a*c?b"));
    return 0;
}