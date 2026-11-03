/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node *rt=st.top();st.pop();
            ans.push_back(rt->data);
            if(rt->left) st.push(rt->left);
            if(rt->right) st.push(rt->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        while(root){
            ans.push_back(root->data);
            if(root->right==NULL){
                root=root->left;
            }
            else{
                Node *temp=root->right;
                while(temp->left && temp->left!=root){
                    temp=temp->left;
                }
                if(temp->left==NULL){
                    temp->left=root;
                    root=root->right;
                }
                else{
                    temp->left=NULL;
                    ans.pop_back();
                    root=root->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

