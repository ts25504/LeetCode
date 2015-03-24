/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> s;
        if (root)
            s.push(root);
        while (!s.empty())
        {
            TreeNode* top_node = s.top();
            s.pop();
            while (top_node)
            {
                if (top_node->right)
                    s.push(top_node->right);
                res.push_back(top_node->val);
                top_node = top_node->left;
            }
        }
        return res;
    }
};
