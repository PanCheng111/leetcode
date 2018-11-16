#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++)
            if (nums[i] <= 0) nums[i] = len + 1;
        for (int i = 0; i < len; i++) {
            int tmp = labs(nums[i]);
            if (tmp > len) continue;
            if (nums[tmp - 1] > 0) nums[tmp - 1] = - nums[tmp - 1];
        }
        for (int i = 0; i < len; i++)
            if (nums[i] > 0) return i + 1;
        return len + 1;
    }
};

int main() {
    Solution s;
    int a[] = {3, 4, 1, 0};
    vector<int> data(a, a+4);
    printf("%d\n", s.firstMissingPositive(data));
    return 0;
}