#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int *stack = new int[len];
        int *check = (int *)calloc(sizeof(int), len);
        int top = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') stack[top++] = i;
            else {
                if (top > 0) {
                    check[stack[top - 1]] = 1;
                    check[i] = 1;
                    top --;
                }
            }    
        }
        int ret = 0, size = 0;
        for (int i = 0; i < len; i++) {
            int cur = i;
            while (cur < len && check[cur]) cur ++;
            size = cur - i;
            if (size > ret) ret = size;
            i = cur;
        }
        return ret;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.longestValidParentheses(")()())"));
    return 0;
}