#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace std;

class Solution {
private:
    int *fa;

public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        set<int> exist;
        for (int i = 0; i < len; i++)
            exist.insert(nums[i]);
        set<int>::iterator iter = exist.begin();
        int ret = 0;
        while (iter != exist.end()) {
            //printf("%d\n", *iter);
            if (exist.find(*iter - 1) == exist.end()) {
                int cur = *iter, be = *iter;
                while (exist.find(cur + 1) != exist.end()) { cur ++; iter ++; }
                ret = ret < (cur - be + 1) ? (cur - be + 1) : ret;
            }
            iter ++;
        }
        return ret;
    }
};

int main() {
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(a, a+6);
    Solution s;
    printf("%d\n", s.longestConsecutive(nums));
    return 0;
}