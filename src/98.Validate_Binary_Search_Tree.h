/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */

#include <limits.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long left, long right)
    {
        if (root == NULL)
            return true;
        return root->val > left
            && root->val < right
            && check(root->left, left, root->val)
            && check(root->right, root->val, right);
    }
};
