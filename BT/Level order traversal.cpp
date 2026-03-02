/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) 
    {
        // code here
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>store;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                store.push_back(temp->data);
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            ans.push_back(store);
        }
        return ans;
    }
};