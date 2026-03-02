/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node *mirrorTree(Node *root)
    {
        if(root==NULL) return root;
        Node *temp=mirrorTree(root->left);
        root->left=mirrorTree(root->right);
        root->right=temp;
        
        return root;
    }
    void mirror(Node* root) 
    {
        // code here
        if(root==NULL) return;
        root=mirrorTree(root );
    }
};