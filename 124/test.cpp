#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    int ans;

public:
    int findPath(TreeNode *x) {
        int ret = x->val;
        if (ret > ans) ans = ret;
        if (x->left == NULL && x->right == NULL) {
            return ret;
        }
        int left = (x->left != NULL) ? findPath(x->left) : 0;
        int right = (x->right != NULL) ? findPath(x->right) : 0;
        ans = ans < left + right + ret ? left + right + ret : ans;
        ans = ans < right + ret ? right + ret : ans;
        ans = ans < left + ret ? left + ret : ans;
        ret = ret < left + x->val ? left + x->val : ret;
        ret = ret < right + x->val ? right + x->val : ret;
        return ret;
    }

    int maxPathSum(TreeNode* root) {
        ans = -2147483647;
        findPath(root);
        return ans;
    }

};

int main() {
    TreeNode *a = new TreeNode(-10);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    c->left = d;
    c->right = e;

    Solution s;
    printf("%d\n", s.maxPathSum(a));
    
    return 0;
}