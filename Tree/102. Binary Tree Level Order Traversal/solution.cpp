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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> result;
        vector<int> v;
        TreeNode* temp;
        while(!q.empty())
        {
            temp = q.front();
            if(temp!=NULL)
            {
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                v.push_back(temp->val);
            }
            else
            {
                q.pop();
                if(!q.empty())
                    q.push(NULL);
                result.push_back(v);
                v.clear();
            }
        }
        return result;
    }
};