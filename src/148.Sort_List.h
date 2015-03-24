/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        return mergeList(sortList(head), sortList(p2));
    }
    ListNode* mergeList(ListNode* ph1, ListNode* ph2)
    {
        if (ph1 == NULL)
            return ph2;
        if (ph2 == NULL)
            return ph1;
        ListNode* new_head = NULL;
        if (ph1->val < ph2->val)
        {
            new_head = ph1;
            new_head->next = mergeList(ph1->next, ph2);
        }
        else
        {
            new_head = ph2;
            new_head->next = mergeList(ph1, ph2->next);
        }
        return new_head;
    }
};
