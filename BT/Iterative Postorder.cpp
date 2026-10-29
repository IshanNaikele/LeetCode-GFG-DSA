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

