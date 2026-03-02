// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) 
    {
        // code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int maxVal=INT_MIN;
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
            
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                maxVal=max(maxVal,temp->data);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};