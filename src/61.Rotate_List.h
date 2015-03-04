/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int len = 1;
        ListNode* p1 = head;
        while (p1->next)
        {
            ++len;
            p1 = p1->next;
        }
        k %= len;
        if (k == 0)
            return head;
        p1->next = head;
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        while (k-- > 0)
            fast_ptr = fast_ptr->next;
        while (fast_ptr != p1)
        {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        head = slow_ptr->next;
        slow_ptr->next = NULL;
        return head;
    }
};
