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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        if(root==NULL)
            return sum;
        if(root->val%2==0)
        {
            if(root->left)
            {
                if(root->left->left)
                    sum+=root->left->left->val;
                if(root->left->right)
                    sum+=root->left->right->val;
            }
            if(root->right)
            {
                if(root->right->left)
                    sum+=root->right->left->val;
                if(root->right->right)
                    sum+=root->right->right->val;
            }
        }
        return sum+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};