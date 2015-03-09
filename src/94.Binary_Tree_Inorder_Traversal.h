/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL)
            return res;
        while (!st.empty() || root)
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
