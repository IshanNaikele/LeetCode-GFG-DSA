#incllude<iostream>
#include<vector>
using namespace std;

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
    void find(Node *root,int index,int &left,int &right){
        if(root==NULL) return ;
        left=min(left,index);
        right=max(right,index);
        find(root->left,index-1,left,right);
        find(root->right,index+1,left,right);
    }
    
    vector<vector<int>> verticalOrder(Node *root) {
        if(root==NULL) return {{}};
        int ind=0,left=0,right=0;
        find(root,ind,left,right);
        queue<Node*>q;q.push(root);
        queue<int>index;index.push(0);
        vector<vector<int>>negIndex(abs(left)+1);
        vector<vector<int>>posIndex(right+1);
        
        while(!q.empty()){
            Node *rt=q.front();q.pop();
            int i=index.front();index.pop();
            
            if(i>=0){
                posIndex[i].push_back(rt->data);
            }
            else{
                negIndex[abs(i)].push_back(rt->data);
            }
            if(rt->left){
                q.push(rt->left);
                index.push(i-1);
            }
            if(rt->right){
                q.push(rt->right);
                index.push(i+1);
            }
        }
        
        vector<vector<int>>ans;
        for(int i=negIndex.size()-1;i>0;i--){
            ans.push_back(negIndex[i]);
        }
        for(int i=0;i<posIndex.size();i++){
            ans.push_back(posIndex[i]);
        }
        return ans;
    }
};