/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是
按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。如果，
我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
可以假设除了数字0外，这两个数都不会以0开头。
*/
class Solution {
public:
    /*
    思路，类似于数字电路里的加法过程，考虑本位和进位即可
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* h = res;
        int sum = 0, c = 0;
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + c;
            c = sum / 10;
            sum = sum % 10;

            h->next = new ListNode(sum);
            h = h->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL)
        {
            while(l2 != NULL)
            {
                sum = l2->val + c;
                c = sum / 10;
                sum = sum % 10;
                h->next = new ListNode(sum);
                h = h-> next;
                l2 = l2->next;
            }
        }

        if (l2 == NULL)
        {
            while(l1 != NULL)
            {
                sum = l1->val + c;
                c = sum / 10;
                sum = sum % 10;
                h->next = new ListNode(sum);
                h = h->next;
                l1 = l1->next;
            }
        }

        if (c)
            h->next = new ListNode(1);
        
        return res->next;
    }
};