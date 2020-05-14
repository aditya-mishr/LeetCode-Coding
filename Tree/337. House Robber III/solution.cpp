/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int root_in = root->val;
            if(root->left && root->left->left)
                root_in += rob(root->left->left);
            if(root->left && root->left->right)
                root_in += rob(root->left->right);
            if(root->right && root->right->left)
                root_in += rob(root->right->left);
            if(root->right && root->right->right)
                root_in += rob(root->right->right);
            
            int root_out = 0;
            if(root->left)
                root_out += rob(root->left);
            if(root->right)
                root_out += rob(root->right);
            
            return max(root_in,root_out);
                
        }
    }
};