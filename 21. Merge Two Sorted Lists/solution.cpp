/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* l1,ListNode* l2)
{
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    ListNode* head=NULL;
    ListNode* p = NULL;
    ListNode* q;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                q = l1;
                l1 = l1->next;
                
            }
            else
            {
                q = l2;
                l2=l2->next;
            }
            q->next = NULL;
            if(p==NULL)
            {
                head = q;
                p = q;
            }
            else
            {
                p->next = q;
                p = q;
            }
        }
        else if(l1==NULL)
        {
            p->next = l2;
            l2=NULL;
        }
        else
        {
            p->next = l1;
            l1=NULL;
        }
    }
    return head;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return merge(l1,l2);
    }
};