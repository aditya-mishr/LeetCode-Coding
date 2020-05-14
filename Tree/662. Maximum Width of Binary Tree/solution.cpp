/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check(queue<TreeNode*> q)
{
    int i =1;
    int e =1;
    
    while(!q.empty())
    {
        if(q.front()!=NULL)
            e=i;
        i++;
        q.pop();
    }
    return e;
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int max_width=0;
        int w =0;
        TreeNode* temp;
        while(!q1.empty() || !q2.empty())
        {
            w = check(q1);
            if(max_width< w)
                max_width = w;
            
            while(!q1.empty())
            {
                temp = q1.front();
                q1.pop();
                if(temp && temp->left!=NULL)
                    q2.push(temp->left);
                else if(temp && temp->left==NULL && !q2.empty())
                    q2.push(temp->left);
                else if (temp==NULL && !q2.empty())
                {   
                    q2.push(NULL);
                    q2.push(NULL);
                }
                if(temp && temp->right!=NULL)
                    q2.push(temp->right);
                else if(temp && temp->right==NULL && !q2.empty())
                    q2.push(temp->right);
            }
            
            w = check(q2);
            if(max_width< w)
                max_width = w;
            
            while(!q2.empty())
            {
                temp = q2.front();
                q2.pop();
                if(temp && temp->left!=NULL)
                    q1.push(temp->left);
                else if(temp && temp->left==NULL && !q1.empty())
                    q1.push(temp->left);
                else if (temp==NULL && !q1.empty())
                {   
                    q1.push(NULL);
                    q1.push(NULL);
                }
                if(temp && temp->right!=NULL)
                    q1.push(temp->right);
                else if(temp && temp->right==NULL && !q1.empty())
                    q1.push(temp->right);
            }
        }
        return max_width;
    }
};