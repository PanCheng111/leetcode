#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:

    struct Node {
        int value;
        int idx;
        Node(int _value, int _idx) : value(_value), idx(_idx) {}
    };

public:
    
    static int cmp(const Node &a, const Node &b) {
        return a.value < b.value;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        vector<Node> tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(Node(nums[i], i));
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int len = nums.size();
        int min_result = 2147483647;
        int ret;
        for (int i = 0; i < len; i++) {
            int ed = len - 1;
            for (int j = i + 1; j < len; j++) {
                while (ed > j + 1 && tmp[ed].value + tmp[i].value + tmp[j].value > target) ed --;
                if (ed > j && labs(tmp[ed].value + tmp[i].value + tmp[j].value - target) < min_result) {
                    min_result = labs(tmp[ed].value + tmp[i].value + tmp[j].value - target);
                    ret = tmp[ed].value + tmp[i].value + tmp[j].value;
                }
                if (ed + 1 > j && ed + 1 < len && labs(tmp[ed + 1].value + tmp[i].value + tmp[j].value - target) < min_result) {
                    min_result = labs(tmp[ed + 1].value + tmp[i].value + tmp[j].value - target);
                    ret = tmp[ed + 1].value + tmp[i].value + tmp[j].value;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr + 4);
    int ret = s.threeSumClosest(nums, 1);
    printf("%d\n", ret);
    return 0;
}