/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Type
{
    bool is_bst;
    int left_most;
    int right_most;
    
};
Type valid_bst(TreeNode* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        Type t = {true,root->val,root->val};
        return t;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        Type right = valid_bst(root->right);
        if(right.is_bst==true && root->val < root->right->val && root->val < right.left_most)
            right.is_bst = true;
        else
            right.is_bst = false;
        right.left_most = root->val;
        return right;
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        Type left = valid_bst(root->left);
        if(left.is_bst==true && root->val > root->left->val && root->val > left.right_most)
            left.is_bst =true;
        else
            left.is_bst = false;
        left.right_most = root->val;
        return left;
    }
    else
    {
        Type left = valid_bst(root->left);
        Type right = valid_bst(root->right);
        Type middle;
        if(left.is_bst==true && right.is_bst==true && root->val > root->left->val && root->val > left.right_most && root->val < root->right->val && root->val < right.left_most)
        {
            right.is_bst=true;
        }
        else
            right.is_bst = false;
        right.left_most = left.left_most;
        return right;
    }
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    if(root==NULL)
        return true;
    Type t = valid_bst(root);
    return t.is_bst;
    }
};