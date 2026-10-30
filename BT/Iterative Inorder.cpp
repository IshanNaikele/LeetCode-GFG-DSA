/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<Node*>st;st.push(root);
        stack<int>visited;visited.push(0);
         
        while(!st.empty()){
            Node *rt=st.top();st.pop();
            int count=visited.top();visited.pop();
            if(count==1) {
                ans.push_back(rt->data);
                continue;
            }
            
            if(rt->right) {
                st.push(rt->right);
                visited.push(0);
            }
            
             
            st.push(rt);
            visited.push(1);
            
            if(rt->left)  {
                st.push(rt->left);
                visited.push(0);
            }
            
        }
        return ans;
    }
};
