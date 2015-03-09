/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
            return true;
        return isSameTree(root->left, root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (!(p && q))
            return false;
        return p->val == q->val && isSameTree(p->left, q->right)
            && isSameTree(p->right, q->left);
    }
};
