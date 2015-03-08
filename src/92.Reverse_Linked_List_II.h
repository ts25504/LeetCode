/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (head == NULL || head->next == NULL || m == n)
            return head;
        ListNode* h1 = new ListNode(0);
        h1->next = head;
        ListNode* h2 = h1;
        for (int i = 0; i < m-1; ++i)
            h2 = h2->next;
        ListNode* p = h2->next;
        ListNode* q = p->next;
        if (q == NULL)
            return head;
        ListNode* r = q->next;
        for (int i = m; i < n; ++i)
        {
            q->next = p;
            p = q;
            q = r;
            if (r == NULL)
                break;
            r = r->next;
        }
        h2->next->next = q;
        h2->next = p;
        return h1->next;
    }
};
