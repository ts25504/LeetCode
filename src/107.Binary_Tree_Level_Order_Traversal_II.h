/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 */

#include <vector>
#include <queue>
#include <algorithm>

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
            ++level;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
