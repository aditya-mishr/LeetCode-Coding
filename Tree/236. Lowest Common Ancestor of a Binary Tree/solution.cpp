/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* find_lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL)
        return NULL;
    else if(root->val==p->val || root->val==q->val)
    {
        return root;
    }
    else
    {
        TreeNode* l = find_lca(root->left,p,q);
        TreeNode* r = find_lca(root->right,p,q);
        if(l!=NULL && r!=NULL)
            return root;
        else if(l!=NULL)
            return l;
        else
            return r;
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find_lca(root,p,q);
    }
};