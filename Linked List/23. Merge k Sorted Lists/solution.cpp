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
ListNode* mergelists(vector<ListNode*> &lists,int i,int j)
{
    if(i==j)
        return lists[i];
    else
    {
        int mid = (i+j)/2;
        ListNode* l1 = mergelists(lists,i,mid);
        ListNode* l2 = mergelists(lists,mid+1,j);
        return merge(l1,l2);
    }
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size==0)
            return NULL;
        return mergelists(lists,0,size-1);
        
    }
};