#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "N";
        char tmp[100];
        sprintf(tmp, "%d", root->val);
        string ret = tmp;
        string left = serialize(root->left);
        string right = serialize(root->right);
        return ret + ","+left+","+right;
    }

    // Decodes your encoded data to tree.
    TreeNode* _deserialize(string &data) {
        int idx = data.find_first_of(',');
        string cur = data.substr(0, idx);
        data = data.substr(idx + 1);
        TreeNode *ret;
        if (cur == "N") {
            return NULL;
        }
        ret = new TreeNode(stoi(cur.c_str()));
        ret->left = _deserialize(data);
        ret->right = _deserialize(data);
        return ret;
    }

    TreeNode* deserialize(string data) {
        string mydata = data;
        return _deserialize(mydata);
    }
};

int main() {
    Codec s;
    TreeNode *a = new TreeNode(-10);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    c->left = d;
    c->right = e;

    printf("%s\n", s.serialize(a).c_str());

    TreeNode *ret = s.deserialize(s.serialize(a));
    printf("%s\n", s.serialize(ret).c_str());

}