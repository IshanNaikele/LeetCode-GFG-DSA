/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int find(vector<int>inOrder,int inStart,int inEnd,int target)
    {
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inOrder[i]==target) return i;
        }
        return -1;
    }
    
    Node *Tree(vector<int>inorder,vector<int>preorder,int inStart,int inEnd,int index)
    {
        if(inStart>inEnd) return NULL;
        Node *root=new Node(preorder[index]);
        int pos=find(inorder,inStart,inEnd,preorder[index]);
        root->left=Tree(inorder,preorder,inStart,pos-1,index+1);
        root->right=Tree(inorder,preorder,pos+1,inEnd,index+(pos-inStart)+1);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) 
    {
        // code here
        return Tree(inorder,preorder,0,inorder.size()-1,0);
    }
};