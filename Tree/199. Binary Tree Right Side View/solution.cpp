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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* p;
        // int i=0;
        while(!q.empty())
        {
            // i++;
            p = q.front();
            q.pop();
            if(p!=NULL)
            {
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
                if(q.front()==NULL)
                {
                    result.push_back(p->val);
                    q.push(NULL);
                }
            }
        }
        // cout<<i<<endl;
        return result;
    }
};