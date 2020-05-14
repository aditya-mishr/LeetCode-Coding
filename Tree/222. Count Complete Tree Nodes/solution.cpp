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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int left_tree = countNodes(root->left);
            int right_tree = countNodes(root->right);
            return 1+left_tree+right_tree;
        }
    }
};