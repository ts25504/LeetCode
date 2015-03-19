/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};
class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        int res = 0;
        if (root == NULL)
            return 0;
        dfs(root, res, root->val);
        return res;
    }
    void dfs(TreeNode* root, int& res, int cur_sum)
    {
        if (!root->left && !root->right)
        {
            res += cur_sum;
            return;
        }
        if (root->left)
            dfs(root->left, res, cur_sum * 10 + root->left->val);
        if (root->right)
            dfs(root->right, res, cur_sum * 10 + root->right->val);
    }
};
