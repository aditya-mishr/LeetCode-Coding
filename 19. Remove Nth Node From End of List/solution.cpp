/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int find_length(ListNode* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = find_length(head);
        int k = length - n - 1;
        if(k==-1)
        {
            head = head->next;
            return head;
        }
        ListNode* p = head;
        while(k!=0)
        {
            p = p->next;
            k--;
        }
        p->next = p->next->next;
        return head;
        
    }
};