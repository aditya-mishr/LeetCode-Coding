/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void path_sum(TreeNode* root,int sum,vector<int> &v,vector<vector<int>> &result)
{
    if(root!=NULL)
    {
        v.push_back(root->val);
        sum = sum-root->val;
        if(root->left==NULL && root->right==NULL && sum==0)
        {
            result.push_back(v);
            v.pop_back();
            return;
        }
        else
        {
            if(root->left!=NULL)
            {
                path_sum(root->left,sum,v,result);
            }
            if(root->right!=NULL)
                path_sum(root->right,sum,v,result);
        }
        v.pop_back();
        sum = sum+root->val;
        return;
    }
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v;
        vector<vector<int>> result;
        path_sum(root,sum,v,result);
        return result;
    }
};