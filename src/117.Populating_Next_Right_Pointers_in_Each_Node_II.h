/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    void connect(TreeLinkNode* root)
    {
        if (root == NULL)
            return;
        if (!root->left && !root->right)
            return;
        if (root->left)
        {
            if (root->right)
                root->left->next = root->right;
            else
            {
                TreeLinkNode* next_node = root->next;
                while (next_node)
                {
                    if (next_node->left)
                    {
                        root->left->next = next_node->left;
                        break;
                    }
                    else if (next_node->right)
                    {
                        root->left->next = next_node->right;
                        break;
                    }
                    next_node = next_node->next;
                }
            }
        }
        if (root->right)
        {
            TreeLinkNode* next_node = root->next;
            while (next_node)
            {
                if (next_node->left)
                {
                    root->right->next = next_node->left;
                    break;
                }
                else if (next_node->right)
                {
                    root->right->next = next_node->right;
                    break;
                }
                next_node = next_node->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};

