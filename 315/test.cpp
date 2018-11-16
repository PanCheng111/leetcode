#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    int *data;
    int N;
public:

    int lowbit(int x) {
        return x & (-x);
    }

    void insert(int x) {
        for (int i = x; i <= N; i += lowbit(i))
            data[i] += 1;
    }

    int query(int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            ret += data[i];
        return ret;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        data = new int[len + 1];
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        memset(data, 0, sizeof(int) * len);
        for (int i = 0; i < len; i++) 
            nums[i] = find(tmp.begin(), tmp.end(), nums[i]) - tmp.begin() + 1;
        vector<int> ans;
        N = len;
        for (int i = len - 1; i >= 0; i--) {
            ans.push_back(query(nums[i] - 1));
            insert(nums[i]);
        }
        vector<int> ret;
        for (int i = len - 1; i >= 0; i --)
            ret.push_back(ans[i]);
        return ret;
    }
};

int main() {
    Solution s;
    int a[] = {5, 2, 6, 1};
    vector<int> list(a, a+4);
    vector<int> ret = s.countSmaller(list);
    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);
    printf("\n");
    return 0;
}