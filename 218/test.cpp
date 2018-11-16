#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
private:
    const static int MAXHEIGHT = 10000;
    int *nums, *tree_max, *heights;

public:

    struct Node {
        int loc, height, label;
        Node(int _loc, int _height, int _label) : loc(_loc), height(_height), label(_label) {}
    };

    static bool cmp(const Node &a, const Node &b) {
        return a.loc < b.loc || (a.loc == b.loc && a.label < b.label);
    }

    int maxer(int a, int b) {
        if (a > b) return a;
        return b;
    }

    void insertLineTree(int kth, int left, int right, int x, int delta) {
        if (left > right) return;
        if (left > x || right < x) return;
        if (left == right && left == x) {
            nums[kth] += delta;
            if (nums[kth] > 0) tree_max[kth] = heights[left];
            else tree_max[kth] = 0;
            return;
        }
        insertLineTree(kth * 2 + 1, left, (left + right) / 2, x, delta);
        insertLineTree(kth * 2 + 2, (left + right) / 2 + 1, right, x, delta);
        tree_max[kth] = maxer(tree_max[kth * 2 + 1], tree_max[kth * 2 + 2]);
    }

    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        int len = buildings.size();
        vector<Node> lines;
        heights = new int[len + 1];
        for (int i = 0; i < len; i++) {
            vector<int> building = buildings[i];
            Node left(building[0], building[2], 1);
            Node right(building[1], building[2], -1);
            lines.push_back(left);
            lines.push_back(right);
            heights[i] = building[2];
        }
        sort(lines.begin(), lines.end(), cmp);
        sort(heights, heights + len);
        int len_height = unique(heights, heights + len) - heights;
        int cur_height = 0;
        vector<pair<int, int> > ret;
        tree_max = new int[MAXHEIGHT * 10];
        nums = new int[MAXHEIGHT * 10];
        for (int i = 0; i < len * 2; i++) {
            int cur = i; int height = 0;
            while (cur < len * 2 && lines[cur].loc == lines[i].loc) {
                int height_idx = find(heights, heights + len_height, lines[cur].height) - heights;
                insertLineTree(0, 0, MAXHEIGHT, height_idx, lines[cur].label);
                cur ++;
            }
            height = tree_max[0]; //getLineTree(0, 0, MAXHEIGHT);
            i = cur - 1;
            if (height != cur_height) {
                ret.push_back(make_pair(lines[i].loc, height));
            }
            cur_height = height;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> rect1; rect1.push_back(2); rect1.push_back(9); rect1.push_back(10); 
    vector<int> rect2; rect2.push_back(3); rect2.push_back(7); rect2.push_back(15); 
    vector<int> rect3; rect3.push_back(5); rect3.push_back(12); rect3.push_back(12); 
    vector<int> rect4; rect4.push_back(15); rect4.push_back(20); rect4.push_back(10); 
    vector<int> rect5; rect5.push_back(19); rect5.push_back(24); rect5.push_back(8); 
    vector<vector<int> > builds ;
    builds.push_back(rect1);
    builds.push_back(rect2);
    builds.push_back(rect3);
    builds.push_back(rect4);
    builds.push_back(rect5);

    vector<pair<int, int> > ret = s.getSkyline(builds);
    for (int i = 0; i < ret.size(); i++)
        printf("%d, %d\n", ret[i].first, ret[i].second);
    return 0;
}
