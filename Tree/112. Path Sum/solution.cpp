/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool path_sum(TreeNode* root,int sum)
{
        if(root->left==NULL && root->right==NULL && sum==root->val)
            return true;
        else if(root->left==NULL && root->right==NULL && sum!=root->val)
            return false;
        else
        {
            bool l = false;
            if(root->left!=NULL)
                l=path_sum(root->left,sum-root->val);
            bool r = false;
            if(root->right!=NULL)
                r=path_sum(root->right,sum-root->val);
            return l||r;
        }
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        else
            return path_sum(root,sum);
   
    }
};