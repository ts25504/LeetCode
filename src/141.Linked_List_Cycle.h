/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        if (p1 == NULL)
            return false;
        while (p1 && p2)
        {
            p1 = p1->next;
            if (p2->next)
                p2 = p2->next->next;
            else
                return false;
            if (p1 == p2)
                return true;
        }
        return false;
    }
};
