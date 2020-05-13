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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* curr = root;
        TreeNode* n;
        while(!s.empty() || curr!=NULL)
        {
            if(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            else if(curr==NULL)
            {
                n = s.top();
                v.push_back(n->val);
                s.pop();
                curr = n->right;
            }
                
        }
        return v;
    }
};