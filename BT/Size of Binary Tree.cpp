/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* root) 
    {
        // code here
        if(root==NULL) return 0;
        return getSize(root->left)+getSize(root->right)+1;
    }
};