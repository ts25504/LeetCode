/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* p1 = head;
        int len = 0;
        while (p1)
        {
            p1 = p1->next;
            ++len;
        }
        ListNode* h = head + (len + 1) / 2;
        h = reverseList(h);
        p1 = head + (len - 1) / 2;
        p1->next = NULL;
        ListNode* p2 = head, *p3 = h, *p4 = p3->next;
        while (p2 && p3)
        {
            p4 = p3->next;
            p3->next = p2->next;
            p2->next = p3;
            p3 = p4;
            p2 = p2->next->next;
        }
    }
    ListNode* reverseList(ListNode * head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p1 = head, *p2 = p1->next, *p3 = p2->next;
        while (p3)
        {
            if (p1 == head)
                p1->next = NULL;
            p2->next= p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        return p2;
    }
};
