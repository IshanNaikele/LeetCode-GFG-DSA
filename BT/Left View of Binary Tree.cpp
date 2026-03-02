//Approach 1 :Iterative Using Queue (Level Order Traversal)

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
     
    vector<int> leftView(Node *root) 
    {
        // code here
        
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
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
        return ans;
        
    }
};

