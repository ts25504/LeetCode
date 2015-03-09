/*
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
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
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> res;
        generate(0, n-1, res);
        return res;
    }

    void generate(int left, int right, vector<TreeNode*>& ans)
    {
        if (left > right)
        {
            ans.push_back(NULL);
            return;
        }

        for (int i = left; i <= right; ++i)
        {
            vector<TreeNode*> left_tree = generate(left, i - 1);
            vector<TreeNode*> right_tree = generate(i + 1, right);
            for (int j = 0; j < left_tree.size(); ++j)
                for (int k = 0; k < right_tree.size(); ++k)
                {
                    TreeNode* node = new TreeNode(i + 1);
                    ans.push_back(node);
                    node->left = left_tree[j];
                    node->right = right_tree[k];
                }
        }
        return ans;
    }
};
