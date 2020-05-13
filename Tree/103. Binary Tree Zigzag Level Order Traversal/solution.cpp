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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        TreeNode* temp;
        bool turn = 0;//0:left-right,1:right-left
        vector<vector<int>> result;
        vector<int> v;
        if(root==NULL)
            return {};
        q.push_back(root);
        q.push_back(NULL);
        while(!q.empty())
        {
            if(turn==0)
            {
                temp = q.front();
                if(temp!=NULL)
                {
                    q.pop_front();
                    v.push_back(temp->val);
                    if(temp->left!=NULL)
                        q.push_back(temp->left);
                    if(temp->right!=NULL)
                        q.push_back(temp->right);
                }
                else
                {
                    q.pop_front();
                    turn  = (turn+1)%2;
                    if(!q.empty())
                        q.push_front(NULL);
                    result.push_back(v);
                    v.clear();
                }
                        
            }
            else
            {
                temp = q.back();
                if(temp!=NULL)
                {
                    q.pop_back();
                    v.push_back(temp->val);
                    if(temp->right!=NULL)
                        q.push_front(temp->right);
                    if(temp->left!=NULL)
                        q.push_front(temp->left);
                }
                else
                {
                    q.pop_back();
                    turn  = (turn+1)%2;
                    if(!q.empty())
                        q.push_back(NULL);
                    result.push_back(v);
                    v.clear();
                }  
            }
        }
        return result;
    }
};