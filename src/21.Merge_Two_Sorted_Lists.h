/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* l3 = new ListNode(0);
        ListNode* p3 = l3;
        while (l1 || l2)
        {
            if (l1 && (l2 == NULL  || l1->val <= l2->val))
            {
                p3->next = l1;
                l1 = l1->next;
            }
            else
            {
                p3->next = l2;
                l2 = l2->next;
            }
            p3 = p3->next;
        }
        p3 = l3;
        l3 = l3->next;
        free(p3);
        return l3;
    }
};
