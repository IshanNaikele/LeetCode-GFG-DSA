//Approach 1 :Using Recursion (Same as Top View )

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
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
    
    void BView(Node *root,vector<int>&ans,vector<int>&store,int index,int level)
    {
        if(root==NULL) return ;
        if(store[index]<=level)
        {
            ans[index]=root->data;
            store[index]=level;
        }
        
        BView(root->left,ans,store,index-1,level+1);
        BView(root->right,ans,store,index+1,level+1);
    }
    vector<int> bottomView(Node *root) 
    {
        // code here
        if(root==NULL) return {};
        int left=0,right=0,pos=0,level=0;
        find(root,pos,left,right);
        
        vector<int>ans(right-left+1);
        vector<int>store(right-left+1,INT_MIN);
        
        BView(root,ans,store,abs(left),level);
        return ans;
    }
};

//Approach 2 :Using Level Order Traversal Technique 

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
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
    
     
    vector<int> bottomView(Node *root) 
    {
        // code here
        // code here
        if(root==NULL) return {};
        int left=0,right=0,pos=0;
        find(root,pos,left,right);
        
        vector<int>ans(right-left+1);
        vector<int>store(right-left+1,INT_MIN);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(abs(left));
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
                int loc=index.front();
                index.pop();
                if(store[loc]<=level) 
                {
                    ans[loc]=temp->data;
                    store[loc]=level;
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
            level++;
        }
        return ans;
    }
};