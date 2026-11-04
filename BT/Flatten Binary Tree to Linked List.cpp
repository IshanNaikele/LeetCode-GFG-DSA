/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void flatten(Node* root) {
        Node *ans=root;
        while(root){
            if(root->left==NULL){
                root=root->right;
            }
            else{
                Node *temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right=root->right;
                Node *curr=root->left;
                root->right=curr;
                root->left=NULL;
                root=curr;
            }
        }
        
    }
};
