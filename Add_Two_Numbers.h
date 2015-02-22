/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#ifndef Add_Two_Numbers_h
#define Add_Two_Numbers_h

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3 = new ListNode(0);
        ListNode* num1 = l1;
        ListNode* num2 = l2;
        ListNode* num3 = l3;
        int ex = 0;

        while (!(num1 == NULL && num2 == NULL))
        {
            if (num1 != NULL && num2 != NULL)
            {
                num3->val = (num1->val + num2->val + ex) % 10;
                ex = (num1->val + num2->val + ex) / 10;
                num1 = num1->next;
                num2 = num2->next;
                if (!(num1 == NULL && num2 == NULL))
                {
                    ListNode* node = new ListNode(0);
                    num3->next = node;
                    num3 = node;
                }
            }
            else if (num1 != NULL && num2 == NULL)
            {
                num3->val = (num1->val + ex) % 10;
                ex = (num1->val + ex) / 10;
                num1 = num1->next;
                if (num1 != NULL)
                {
                    ListNode* node = new ListNode(0);
                    num3->next = node;
                    num3 = node;
                }
            }
            else if (num1 == NULL && num2 != NULL)
            {
                num3->val = (num2->val + ex) % 10;
                ex = (num2->val + ex) / 10;
                num2 = num2->next;
                if (num2 != NULL)
                {
                    ListNode* node = new ListNode(0);
                    num3->next = node;
                    num3 = node;
                }
            }
        }
        if (ex != 0)
        {
            ListNode* node = new ListNode(ex);
            num3->next = node;
        }
        return l3;
    }
};
#endif
