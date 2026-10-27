/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    void find(Node *root,int index,int &left){
        if(root==NULL) return ;
        left=max(left,index);
        find(root->left,index+1,left);
        find(root->right,index,left);
    }
    
    void diagonalTraversal(Node *root,vector<vector<int>>&ans,int left ){
        if(root==NULL) return ;
        
        ans[left].push_back(root->data);
        diagonalTraversal(root->left,ans,left+1 );
        diagonalTraversal(root->right,ans,left );
    }
    
    vector<int> diagonal(Node *root) {
        if(root==NULL) return {};
        int ind=0,left=0;
        find(root,ind,left);
        vector<vector<int>>ans(left+1);
        diagonalTraversal(root,ans,0);
        vector<int>result;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++) result.push_back(ans[i][j]);
        }
        return result;
    }
};