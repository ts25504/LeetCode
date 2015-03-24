/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> vec;
        if (root == NULL)
            return vec;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* p = NULL;
        while (!s.empty())
        {
            top_node = s.top();
            s.pop();
            vec.insert(vec.begin(), top_node->val);
            if (top_node->left)
                s.push(top_node->left);
            if (top_node->right)
                s.push(top_node->right);
        }
        return vec;
    }
};
