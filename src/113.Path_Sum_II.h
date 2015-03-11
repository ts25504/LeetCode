/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > res;
        vector<int> ans;
        if (root == NULL)
            return res;
        dfs(root, 0, sum, ans, res);
        return res;
    }
    void dfs(TreeNode* root, int cur, int sum, vector<int>& ans,
            vector<vector<int> >& res)
    {
        if (cur + root->val == sum && !root->left && !root->right)
        {
            ans.push_back(root->val);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        if (cur + root->val != sum && !root->left && !root->right)
            return;

        if (root->left && root->right)
        {
            ans.push_back(root->val);
            dfs(root->left, cur+root->val, sum, ans, res);
            dfs(root->right, cur+root->val, sum, ans, res);
            ans.pop_back();
        }
        else if (!root->left && root->right)
        {
            ans.push_back(root->val);
            dfs(root->right, cur+root->val, sum, ans, res);
            ans.pop_back();
        }
        else if (!root->right && root->left)
        {
            ans.push_back(root->val);
            dfs(root->left, cur+root->val, sum, ans, res);
            ans.pop_back();
        }

    }
};
