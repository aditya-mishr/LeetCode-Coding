/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool prune_tree(TreeNode* root)
{
    if(root==NULL)
        return false;
    else
    {
        bool l = prune_tree(root->left);
        bool r = prune_tree(root->right);
        if(l==false)
            root->left = NULL;
        if(r==false)
            root->right = NULL;
        
        if(l==false && r==false)
            return root->val;
        else 
            return l||r;
    }
}
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = prune_tree(root);
        if(flag==true)
            return root;
        else
            return NULL;
    }
};