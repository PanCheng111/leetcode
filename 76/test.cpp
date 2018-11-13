#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    int req[256];
    int count[256];
public:
    string minWindow(string s, string t) {
        int lent = t.length();
        int lens = s.length();
        memset(req, 0, sizeof(req));
        memset(count, 0, sizeof(count));
        for (int i = 0; i < lent; i++)
            req[t[i]] ++;
        int require = 0;
        for (int i = 0; i < 256; i++)
            if (req[i]) require += req[i];
        int p = 0, q = 0, meets = 0;
        while (q < lens && meets < require) {
            count[s[q]] ++;
            if (req[s[q]] && count[s[q]] <= req[s[q]]) meets ++;
            q ++;
        }
        
        if (meets < require) return "";
        int min_len = q, be = 0;
        while (p < lens) {
            count[s[p]] --;
            if (req[s[p]] && count[s[p]] < req[s[p]]) {
                meets --;
                while (q < lens && meets < require) {
                    count[s[q]] ++;
                    if (req[s[q]] && count[s[q]] <= req[s[q]]) meets ++;
                    q ++;
                }
                if (meets < require) return s.substr(be, min_len);
            }
            p++;
            if (q - p < min_len) {
                min_len = q - p;
                be = p;
            }
        }
        return s.substr(be, min_len);
    }
};

int main() {
    Solution s;
    printf("%s\n", s.minWindow("a", "a").c_str());
    return 0;
}