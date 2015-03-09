/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root)
    {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        queue<TreeNode*> node_queue;
        queue<TreeNode*> root_queue;
        int level = 0;
        node_queue.push(root);
        while (!node_queue.empty())
        {
            res.push_back(vector<int>());
            while (!node_queue.empty())
            {
                TreeNode* node = node_queue.front();
                root_queue.push(node);
                node_queue.pop();
            }
            while (!root_queue.empty())
            {
                TreeNode* node = root_queue.front();
                res[level].push_back(node->val);
                root_queue.pop();
                if (node->left)
                    node_queue.push(node->left);
                if (node->right)
                    node_queue.push(node->right);
            }
            if (level % 2 == 1)
                reverse(res[level].begin(), res[level].end());
            ++level;
        }
        return res;
    }
};
