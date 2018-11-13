#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int max_height = 0;
        for (int i = 0; i < len; i++)
            if (max_height < height[i]) max_height = height[i];
        int cur_max = 0, left_loc = 0, right_loc = 0;
        int sum = 0, ori_sum = 0;
        for (int i = 0; i < len; i++) {
            if (height[i] > cur_max) cur_max = height[i];
            sum += cur_max;
            if (cur_max == max_height) {
                left_loc = i;
                break;
            }
        }
        cur_max = 0;
        for (int i = len - 1; i >= 0; i --) {
            if (height[i] > cur_max) cur_max = height[i];
            sum += cur_max;
            if (cur_max == max_height) {
                right_loc = i;
                break;
            }
        }
        if (left_loc == right_loc) sum -= max_height;
        else {
            sum += (right_loc - left_loc - 1) * max_height;
        }
        for (int i = 0; i < len; i++)
            ori_sum += height[i];
        return sum - ori_sum;
    }
};

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(a, a + 12);
    Solution s;
    printf("%d\n", s.trap(height));
    return 0;
}