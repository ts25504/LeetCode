/*
 * Sort a linked list using insertion sort.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* p1 = head, *p2 = p1->next;
        while (p2)
        {
            if (p1->val > p2->val)
            {
                ListNode* ph = h;
                while (ph->next)
                {
                    if (ph->next->val > p2->val)
                    {
                        p1->next = p2->next;
                        p2->next = ph->next;
                        ph->next = p2;
                        break;
                    }
                    ph = ph->next;
                }
                p2 = p1->next;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return h->next;
    }
};
