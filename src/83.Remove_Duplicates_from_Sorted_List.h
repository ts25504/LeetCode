/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2)
        {
            while (p2 != NULL && p1->val == p2->val)
                p2 = p2->next;
            if (p2 == NULL)
            {
                p1->next = NULL;
                break;
            }
            p1->next = p2;
            p1 = p2;
        }
        return head;
    }
};
