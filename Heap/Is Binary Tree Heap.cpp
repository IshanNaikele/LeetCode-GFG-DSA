/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool checkCT(Node* root)
    {
        queue<Node *>q;
        q.push(root);
        bool found=true;
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left)   
            {
                if(!found) return found;
                q.push(temp->left);
            }
            if(temp->right)  
            {
                if(!found) return found;
                q.push(temp->right);
            }
            if(!temp->left)  found=false;
            if(!temp->right) found=false;
            if(!temp->left && temp->right)
            return false;
        }
        return true;
    }
    
    bool checkChild(Node *root)
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left && temp->data < temp->left->data)
            return false;
            if(temp->right && temp->data < temp->right->data) 
            return false;
            
            if(temp->left)
            q.push(temp->left);
            if(temp->right) 
            q.push(temp->right);
        }
        return true;
    }
    bool isHeap(Node* root) 
    {
        // code here
        //Approach :First go & check where it's a complete binary Tree or not 
        //          then check wheather it's max heap or not .
        //          if both true return true ,otherwise false
        Node *temp=root;
        bool found1=checkCT(temp);
        bool found2=checkChild(temp);
        return found1 && found2;
    }
    
};