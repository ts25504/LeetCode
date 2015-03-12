/*
 * Given a binary tree, flatten it to a linked list in-place.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    void flatten(TreeNode* root)
    {
        while (root)
        {
            if (root->left == NULL)
                root = root->right;
            else
            {
                if (root->right)
                {
                    TreeNode* left_node = root->left;
                    while (left_node->right)
                        left_node = left_node->right;
                    left_node->right = root->right;
                }
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};
