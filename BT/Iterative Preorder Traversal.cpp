/* Binary Tree Node Structure
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
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty()){
            Node *rt=st.top();st.pop();
            ans.push_back(rt->data);
            if(rt->right) st.push(rt->right);
            if(rt->left) st.push(rt->left);
        }
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
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        
        while(root){
            ans.push_back(root->data);
            if(root->left==NULL){
                root=root->right;
            }
            else{
                Node *temp=root->left;
                while(temp->right && temp->right!=root){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=root;
                    root=root->left;
                }
                else{
                    temp->right=NULL;
                    ans.pop_back();
                    root=root->right;
                }
            }
        }
        return ans;
    }
};

Approach 2 :- 
/* Binary Tree Node Structure
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
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        
        while(root){
             
            if(root->left==NULL){
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                Node *temp=root->left;
                while(temp->right && temp->right!=root){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    ans.push_back(root->data);
                    temp->right=root;
                    root=root->left;
                }
                else{
                    temp->right=NULL;
                    root=root->right;
                }
            }
        }
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

