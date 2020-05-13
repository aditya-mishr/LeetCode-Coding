/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max_path_sum(TreeNode* root,int &ans)
{
    if(root==NULL)
        return 0;
    else
    {
        int sum = root->val;
        int return_l = root->val;
        int return_r = root->val;
        int l = max_path_sum(root->left,ans);
        int r = max_path_sum(root->right,ans);
        if(l>=0)
        {
            sum+=l;
            return_l +=l;
        }
        if(r>=0)
        {
            sum+=r;
            return_r+=r;
        }
        if(ans<sum)
            ans = sum;
        return return_r>return_l?return_r:return_l;
    }
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = -100000000;
        int p = max_path_sum(root,ans);
        return ans;
    }
};