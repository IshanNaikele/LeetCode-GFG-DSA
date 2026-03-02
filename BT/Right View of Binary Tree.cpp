/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) 
    {
        //  code here
        vector<int>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                if(i==0)
                ans.push_back(temp->data);
                q.pop();
                if(temp->right)
                q.push(temp->right);
                if(temp->left)
                q.push(temp->left);
            }
        }
        return ans;
    }
};