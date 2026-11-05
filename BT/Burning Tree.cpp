/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    bool findPath(Node* root,int target,vector<Node*>&path,Node *&targetNode){
        if(root==NULL) return false;
        
        path.push_back(root);
        if (root->data == target) {
            targetNode=root;
            return true;
        }
        
        if(findPath(root->left,target,path,targetNode) || findPath(root->right,target,path,targetNode)){
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    int findHeight(Node *root){
        if(root==NULL) return -1;
        return max(findHeight(root->left),findHeight(root->right))+1;
    }
    
    void solve(vector<Node*>path,int index,int timeTaken,int &maxHeight,Node *targetNode){
        if(index<0) return ;
        Node *temp=path[index];
        if(temp->left==targetNode){
            maxHeight=max(maxHeight,timeTaken+findHeight(temp->right));
        }
        else{
            maxHeight=max(maxHeight,timeTaken+findHeight(temp->left));
        }
        solve(path,index-1,timeTaken+1,maxHeight,temp);
    }
    
    int minTime(Node* root, int target) {
        vector<Node*>path;
        Node *targetNode=NULL;
        bool flag=findPath(root,target,path,targetNode);
        if(!flag) return -1;
        int height1=0;
        solve(path,path.size()-2,1,height1,targetNode);
        int height2=findHeight(targetNode);
        return max(height1,height2);
    }
};
