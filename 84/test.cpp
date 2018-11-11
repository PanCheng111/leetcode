#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Node {
        int loc, height;
        Node(int _loc, int _height) : loc(_loc), height(_height) {}
    };

public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;
        Node *stack = (Node *)malloc(sizeof(Node) * len);
        int *prev = (int *)malloc(sizeof(int) * len);
        int *suff = (int *)malloc(sizeof(int) * len);
        int top = 0;
        stack[0] = Node(0, heights[0]);
        prev[0] = 0;
        for (int i = 1; i < len; i ++) {
            while (top > -1 && heights[i] <= stack[top].height) top --;
            if (top == -1) prev[i] = 0;
            else  prev[i] = stack[top].loc + 1;
            stack[++top] = Node(i, heights[i]);
        }
        top = 0;
        stack[0] = Node(len - 1, heights[len - 1]);
        suff[len - 1] = len - 1;
        for (int i = len - 2; i >= 0; i --) {
            while (top > -1 && heights[i] <= stack[top].height) top --;
            if (top == -1) suff[i] = len - 1;
            else  suff[i] = stack[top].loc - 1;
            stack[++top] = Node(i, heights[i]);
        }
        int ret = 0;
        for (int i = 0; i < len; i++) {
            //printf("%d, %d\n", prev[i], suff[i]);
            if ((suff[i] - prev[i] + 1) * heights[i] > ret)
                ret = (suff[i] - prev[i] + 1) * heights[i];
        }
        return ret;
    }
};

int main() {
    int a[] = {2,1,5,6,2,3};
    vector<int> nums(a, a+6);
    Solution s;
    printf("%d\n", s.largestRectangleArea(nums));
    return 0;
}