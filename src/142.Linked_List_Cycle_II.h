/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

class Solution {
public:
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
