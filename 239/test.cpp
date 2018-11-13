#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int len = nums.size();
        if (len == 0) return ret;
        int *queue = new int[len + 1];
        int head = 0, tail = 0;
        queue[0] = nums[0];
        for (int i = 1; i < k; i++) {
            while (tail >= head && nums[i] > queue[tail]) tail --;
            queue[++tail] = nums[i];
        }
        ret.push_back(queue[head]);
        for (int i = 1; i <= len - k; i++) {
            if (nums[i - 1] == queue[head]) head ++;
            while (tail >= head && nums[i + k - 1] > queue[tail]) tail --;
            queue[++tail] = nums[i + k - 1];
            ret.push_back(queue[head]);
       }
       return ret;
    }
};

int main() {
    Solution s;
    int a[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums(a, a + 8);
    vector<int> ret = s.maxSlidingWindow(nums, 3);
    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);
    printf("\n");
    return 0;
}