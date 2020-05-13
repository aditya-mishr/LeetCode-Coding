int find_len(ListNode* head)
{
    int len =0;
    while(head!=NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* inter=NULL;
        int len_a =0;
        int len_b =0;
        len_a = find_len(headA);
        len_b = find_len(headB);
        int diff=0;
        if(len_a>len_b)
        {
            diff = len_a - len_b;
            while(diff!=0)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            diff = len_b - len_a;
            while(diff!=0)
            {
                headB= headB->next;
                diff--;
            }
        }
        while(headA!=NULL)
        {
            if(headA == headB)
            {
                inter = headA;
                break;
            }
            headA=headA->next;
            headB=headB->next;
        }
        
        return inter;
    }
        
};