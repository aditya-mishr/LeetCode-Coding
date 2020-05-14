/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int depth(TreeNode* root,int d,TreeNode* &ans ,int &max_depth)
{
    if(max_depth<d)
        max_depth = d;
    if(root==NULL)
        return d;
    else
    {
        int d1 = depth(root->left,d+1,ans,max_depth);
        int d2 = depth(root->right,d+1,ans,max_depth);
        if(d1==d2 && d1==max_depth)
            ans = root;
        return d1>d2?d1:d2;
    }
}
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans=NULL;
        int max_depth=0;
        int d=depth(root,1,ans,max_depth);
        return ans;
    }
};