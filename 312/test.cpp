#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    int **opt;
public:
    int find(int l, int r, vector<int> nums) {
        if (l > r) return 0;
        if (opt[l][r] != -1) return opt[l][r];
        if (l == r) {
            int tmp = nums[l];
            if (l - 1 >= 0) tmp *= nums[l - 1];
            if (r + 1 < nums.size()) tmp *= nums[r + 1];
            return tmp;
        }
        int ret = 0;
        for (int i = l; i <= r; i ++) {
            int tmp = nums[i];
            if (l - 1 >= 0) tmp *= nums[l - 1];
            if (r + 1 < nums.size()) tmp *= nums[r + 1];
            tmp += find(l, i - 1, nums) + find(i + 1, r, nums);
            if (tmp > ret) ret = tmp;
        }
        opt[l][r] = ret;
        return ret;
    }

    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        opt = new int*[len + 1];
        for (int i = 0; i < len; i++) {
            opt[i] = new int[len];
            for (int j = 0; j < len; j++)
                opt[i][j] = -1;
        }
        return find(0, len - 1, nums);
    }
};

int main() {
    int a[] = {3,1,5,8};
    vector<int> nums(a, a+4);
    Solution s;
    printf("%d\n", s.maxCoins(nums));
    return 0;
}