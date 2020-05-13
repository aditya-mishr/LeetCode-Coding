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
    ListNode* oddEvenList(ListNode* head) {
        int k = 1;
        ListNode* n = head;
        ListNode* odd = NULL;
        ListNode* odd_head = NULL;
        ListNode* even = NULL;
        ListNode* even_head = NULL;
        if(head==NULL)
            return NULL;
        while(head)
        {
            if(k%2==1)
            {
                if(odd_head==NULL)
                {
                    odd_head = head;
                    odd = head;
                    head = head->next;
                    odd->next = NULL;
                }
                else
                {
                    odd->next = head;
                    head = head->next;
                    odd = odd->next;
                    odd->next = NULL;
                }
                
            }
            else
            {
                if(even_head==NULL)
                {
                    even_head = head;
                    even = head;
                    head = head->next;
                    even->next = NULL;
                }
                else
                {
                    even->next = head;
                    head = head->next;
                    even = even->next;
                    even->next = NULL;
                }
            }
            k++;
        }
        odd->next = even_head;
        return odd_head;
    }
};