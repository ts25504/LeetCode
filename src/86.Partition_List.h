/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (head == NULL)
            return NULL;
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = p1;
        ListNode* p3 = head;
        while (p3)
        {
            if (p3->val < x)
            {
                ListNode* p4 = new ListNode(p3->val);
                p2->next = p4;
                p2 = p4;
            }
            p3 = p3->next;
        }
        p3 = head;
        while (p3)
        {
            if (p3->val >= x)
            {
                ListNode* p4 = new ListNode(p3->val);
                p2->next = p4;
                p2 = p4;
            }
            p3 = p3->next;
        }
        return p1->next;
    }
};
