/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) 
    {
        // code here
        
        vector<int>ans;
        if(root==NULL) return ans;
        stack<Node*>st1,st2;
        st1.push(root);
        int level=0;
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty())
            {
                int size=st1.size();
            
                for(int i=0;i<size;i++)
                {
                    Node *temp=st1.top();
                    ans.push_back(temp->data);
                    st1.pop();
                    if(temp->right)
                    st2.push(temp->right);
                    if(temp->left)
                    st2.push(temp->left);
                }
            }
            else
            {
                int size=st2.size();
                 
                for(int i=0;i<size;i++)
                {
                    Node *temp=st2.top();
                    ans.push_back(temp->data);
                    st2.pop();
                     
                    if(temp->left)
                    st1.push(temp->left);
                    if(temp->right)
                    st1.push(temp->right);
                }
                
            }
        }
        return ans;
    }
};
 