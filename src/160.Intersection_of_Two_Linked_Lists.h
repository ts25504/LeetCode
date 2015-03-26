/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* p = headA;
        ListNode* res = NULL;
        while (p->next)
        {
            p = p->next;
        }
        p->next = headA;
        res = detectCycle(headB);
        p->next = NULL;
        return res;
    }
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* p1 = head, *p2 = head;
        bool has_cycle = false;
        if (p1 == NULL)
            return NULL;
        while (p1 && p2)
        {
            p1 = p1->next;
            if (p2->next)
                p2 = p2->next->next;
            else
                return NULL;
            if (p1 == p2)
            {
                has_cycle = true;
                break;
            }
        }
        if (has_cycle)
        {
            p1 = head;
            while (p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
        else
            return NULL;
    }
};
