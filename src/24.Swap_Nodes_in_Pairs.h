/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL)
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = new ListNode(0);
        ListNode* p4 = new ListNode(0);
        p3->next = p1;
        int i = 0;
        while (p2)
        {
            if (i % 2 == 0)
            {
                p3->next = p2;
                p1->next = p2->next;
                p2->next = p1;

                if (p1 == head)
                {
                    head = p2;
                }

                p4 = p1;
                p1 = p2;
                p2 = p4;
            }
            p2 = p2->next;
            p1 = p1->next;
            p3 = p3->next;
            ++i;
        }
        return head;
    }
};
