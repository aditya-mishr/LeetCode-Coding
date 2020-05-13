/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build_tree(vector<int> &preorder,int a,int b,vector<int> &inorder,int m,int n)
{
    if(m==n)
    {
        TreeNode* t =new TreeNode(inorder[m]);
        return t;
    }
    else if(m>n)
    {
        return NULL;
    }
    else
    {
        int r = preorder[a];
        int i = m;
        while(inorder[i]!=r)
        {
            i++;
        }
        int no_nodes = i-m;
        TreeNode* root = new TreeNode(r);
        root->left = build_tree(preorder,a+1,a+no_nodes,inorder,m,i-1);
        root->right = build_tree(preorder,a+no_nodes+1,b,inorder,i+1,n);
        return root;
    }
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size_pre = preorder.size();
        int size_in = inorder.size();
        return build_tree(preorder,0,size_pre-1,inorder,0,size_in-1);
    }
};