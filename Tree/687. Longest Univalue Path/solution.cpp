/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int path(TreeNode* root,int &ans)
{
    if(root==NULL)
        return 0;
    else
    {
        int path_length =1;
        int l = path(root->left,ans);
        int r = path(root->right,ans);
        int return_l =1;
        int return_r =1;
        
        if(l!=0 && root->val==root->left->val)
        {
            path_length += l;
            return_l +=l;
        }
        if(r!=0 && root->val==root->right->val)
        {
            path_length+=r;
            return_r +=r;
        }
        if(path_length>ans)
            ans = path_length;
        
        return return_r>return_l?return_r:return_l;
    }
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int p;
        int ans = 0;
        if(root==NULL)
            return 0;
        p = path(root,ans);
        return ans-1;
    }
};