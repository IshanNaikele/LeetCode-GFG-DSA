//Approach 1 :Iterative Approach that uses queue ,vector as Data Structure and uses the logic of level order traversal 

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
    void find(Node *root,int index,int &l,int &r)
    {
        if(root==NULL) return;
        l=min(l,index);
        r=max(r,index);
        find(root->left,index-1,l,r);
        find(root->right,index+1,l,r);
    }
    vector<int> topView(Node *root) 
    {
        // code here
        if(root==NULL) return {};
        int left=0,right=0,pos=0;
        find(root,pos,left,right);
        
        vector<int>ans(right-left+1);
        vector<bool>store(right-left+1,false);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(abs(left));
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
                int loc=index.front();
                index.pop();
                if(store[loc]==false) 
                {
                    ans[loc]=temp->data;
                    store[loc]=true;
                }
                if(temp->left)
                {
                    q.push(temp->left);
                    index.push(loc-1);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    index.push(loc+1);
                }
            }
        }
        return ans;
    }
};