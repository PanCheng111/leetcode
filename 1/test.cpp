#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

    // struct Node {
    //     int value;
    //     int idx;
    //     Node(int _value, int _idx) : value(_value), idx(_idx) {}
    // };

    // int cmp(const Node &a, const Node &b) {
    //     return a.value < b.value;
    // }

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

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Node> tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(Node(nums[i], i));
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int ed, len = nums.size();
        ed = len - 1;
        for (int be = 0; be < len; be ++) {
            while (ed > be && tmp[ed].value + tmp[be].value > target) ed --;
            if (tmp[be].value + tmp[ed].value == target) {
                vector<int> ret;
                ret.push_back(tmp[be].idx);
                ret.push_back(tmp[ed].idx);
                return ret;
            }
        }
    }
};

int main() {
    Solution s;
    int arr[] = {3,2,4};
    vector<int> nums(arr, arr + 3);
    vector<int> ret = s.twoSum(nums, 6);
    printf("[%d, %d]\n", ret[0], ret[1]);
    return 0;
}