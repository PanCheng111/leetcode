#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    bool exist[256];

public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int ret = 0;
        for (int i = 0; i < len; i++) {
            memset(exist, 0, sizeof(exist));
            int tmp = 0;
            for (int j = i; j < len; j++) {
                if (exist[s[j]]) { tmp = j - i; break; }
                exist[s[j]] = true;
            }
            if (tmp == 0) tmp = len - i;
            if (tmp > ret) ret = tmp;
        }
        return ret;
    }
};

int main() {
    Solution s;
   // printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
   // printf("%d\n", s.lengthOfLongestSubstring("bbbbb"));
   // printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));
    printf("%d\n", s.lengthOfLongestSubstring("a"));
    return 0;
}