/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        vector<int> v;
        queue<Node*> q;
        if(root==NULL)
            return {};
        q.push(root);
        q.push(NULL);
        Node* temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp!=NULL)
            {
                for(int i=0;i<temp->children.size();i++)
                {
                    q.push(temp->children[i]);
                }
                v.push_back(temp->val);
            }
            else
            {
                if(!q.empty())
                    q.push(NULL);
                result.push_back(v);
                v.clear();
            }
        }
        return result;
    }
};