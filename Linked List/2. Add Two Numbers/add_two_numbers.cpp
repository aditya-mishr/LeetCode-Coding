/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        int carry = 0;
        int value = 0;
        ListNode* head = l1;
        ListNode* p = l1;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL && l2!=NULL)
            {
                value = l1->val + l2->val + carry;
                l1->val = value%10;
                if(value>9)
                    carry = 1;
                else
                    carry = 0;
                p = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l2==NULL)
            {
                value = l1->val + carry;
                l1->val = value%10;
                if(value>9)
                    carry = 1;
                else
                    carry = 0;
                p = l1;
                l1 = l1->next;
            }
            else if(l1==NULL && l2!=NULL)
            {
                p->next = l2;
                l2=NULL;
                l1 = p->next;
            }
        }
        if(carry == 1)
        {
            ListNode* node = new ListNode(1);
            p->next = node;
        }
        return head;
    }
};