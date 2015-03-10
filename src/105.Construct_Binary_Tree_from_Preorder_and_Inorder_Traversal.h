/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty())
            return NULL;
        return build(preorder.begin(), preorder.end(), inorder.begin(),
                inorder.end());
    }

    template<typename Iter>
    TreeNode* build(Iter pre_beg, Iter pre_end, Iter in_beg, Iter in_end)
    {
        if (pre_beg == pre_end)
            return NULL;
        if (in_beg == in_end)
            return NULL;
        int val = *pre_beg;
        auto in_root = find(in_beg, in_end, val);
        TreeNode* root = new TreeNode(*in_root);
        int left_tree_size = in_root - in_beg;
        root->left = build(pre_beg+1, pre_beg+1+left_tree_size,
                in_beg, in_root);
        root->right = build(pre_beg+1+left_tree_size, pre_end,
                in_root+1, in_end);
        return root;
    }
};
