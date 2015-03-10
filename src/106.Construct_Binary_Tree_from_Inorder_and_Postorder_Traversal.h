/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.empty())
            return NULL;
        return build(inorder.begin(), inorder.end(), postorder.begin(),
                postorder.end());
    }

    template<typename Iter>
    TreeNode* build(Iter in_beg, Iter in_end, Iter post_beg, Iter post_end)
    {
        if (post_beg == post_end)
            return NULL;
        if (in_beg == in_end)
            return NULL;
        int val = *(post_end-1);
        auto in_root = find(in_beg, in_end, val);
        TreeNode* root = new TreeNode(*in_root);
        int left_tree_size = in_root - in_beg;
        root->left = build(in_beg, in_root, post_beg, post_beg+left_tree_size);
        root->right = build(in_root+1, in_end, post_beg+left_tree_size, post_end-1);
        return root;
    }
};
