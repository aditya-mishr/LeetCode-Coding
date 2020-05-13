ListNode* reverse(ListNode* p)
{
    ListNode* head = NULL;
    ListNode* q = NULL;
    while(p)
    {
        q = p;
        p=p->next;
        q->next = head;
        head = q;
    }
    return head;
}
int list_length(ListNode* head)
{
    int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
    return length;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        int length = list_length(head);
        int skip=0;
        if(length%2==0)
        {
            skip = length/2;
        }
        else
            skip = (length+1)/2;
        
        ListNode* p = head;
        ListNode* q = head;
        while(skip>0)
        {
            q = p;
            p = p->next;
            skip--;
        }
        q->next = reverse(p);
        p = q->next;
        while(p)
        {
            if(p->val!=head->val)
                return false;
            else
            {
                p=p->next;
                head=head->next;
            }
        }
        return true;
    }
};