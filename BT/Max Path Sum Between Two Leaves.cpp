/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int maxSum(Node *root,int &sum){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int left=maxSum(root->left,sum);
        int right=maxSum(root->right,sum);
        
        if(root->left && root->right) {
            sum=max(sum,root->data+left+right);
            return root->data+max(left,right);
        }
        
        if(root->left) return root->data+left;
        return root->data+right;
    }
    
    int maxPathSum(Node *root) {
        int sum = INT_MIN;
        int val = maxSum(root, sum);

        if (sum == INT_MIN) return -1   ;

        return sum;
    }
};
   