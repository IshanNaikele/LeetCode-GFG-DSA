/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution 
{
  public:
    int find(vector<int>&inorder,int inStart,int inEnd,int target)
    {
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    
    Node *Tree(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int &index)
    {
        if(inStart>inEnd) return NULL;
        
        Node *root=new Node(postorder[index]);
        index--;
        int pos=find(inorder,inStart,inEnd,root->data);
        
        root->right=Tree(inorder,postorder,pos+1,inEnd,index);
        root->left=Tree(inorder,postorder,inStart,pos-1,index);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        // code here
        int index=inorder.size()-1;
        return Tree(inorder,postorder,0,inorder.size()-1,index);
    }
};