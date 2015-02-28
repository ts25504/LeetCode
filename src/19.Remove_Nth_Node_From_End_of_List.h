/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < n; ++i)
        {
            p2 = p2->next;
        }
        if (p2 == NULL)
        {
            ListNode* p3 = head;
            head = head->next;
            delete(p3);
            return head;
        }

        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* p3 = p1->next;
        p1->next = p3->next;
        delete(p3);
        return head;
    }
};
