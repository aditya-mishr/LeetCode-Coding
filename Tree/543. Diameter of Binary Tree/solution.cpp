/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find_height(TreeNode* root,int &diameter)
{
    if(root==NULL)
        return 0;
    else
    {
        int left_height = find_height(root->left,diameter);
        int right_height = find_height(root->right,diameter);
        if(diameter<left_height+right_height)
        {
            diameter = left_height+right_height;
        }
        if(left_height>right_height)
            return 1+left_height;
        return 1+right_height;
    }
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        find_height(root,diameter);
        return diameter;
    }
};