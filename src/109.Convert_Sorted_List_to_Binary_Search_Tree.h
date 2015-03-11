/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        build(head, NULL);
    }

    TreeNode* build(ListNode* head, ListNode* tail)
    {
        if (head == tail)
            return NULL;
        if (head->next == tail)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != tail && fast != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head, slow);
        root->right = build(slow->next, tail);
        return root;
    }
};
