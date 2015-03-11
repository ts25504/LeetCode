/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

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
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL)
            return true;
        if (depth(root->left) - depth(root->right) >= -1 &&
                depth(root->left) - depth(root->right) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }

    int depth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
