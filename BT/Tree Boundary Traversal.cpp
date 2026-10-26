/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void LeftSub(Node *root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return ;
        ans.push_back(root->data);
        LeftSub(root->left,ans);
        if(root->left==NULL) LeftSub(root->right,ans);
    }
    
    void LeafNodes(Node *root,vector<int>&ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(root->data);
            return;
        }
        LeafNodes(root->left,ans);
        LeafNodes(root->right,ans);
    }
    
    void RightSub(Node *root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return ;
        RightSub(root->right,ans);
        if(root->right==NULL) RightSub(root->left,ans);
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        //Lert SubTree 
        LeftSub(root->left,ans);
        //Leaf Nodes
        if(root->left || root->right)
        LeafNodes(root,ans);
        //Right SubTree 
        RightSub(root->right,ans);
        
        return ans;
    }
};