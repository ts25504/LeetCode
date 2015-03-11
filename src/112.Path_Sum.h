/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL)
            return false;
        return dfs(root, 0, sum);
    }

    bool dfs(TreeNode* root, int cur, int sum)
    {
        if (cur + root->val == sum && !root->left && !root->right)
            return true;
        if (cur + root->val != sum && !root->left && !root->right)
            return false;
        if (root->left && root->right)
        {
            return dfs(root->left, cur+root->val, sum) ||
                dfs(root->right, cur+root->val, sum);
        }
        if (!root->left && root->right)
            return dfs(root->right, cur+root->val, sum);
        if (!root->right && root->left)
            return dfs(root->left, cur+root->val, sum);
    }
}
