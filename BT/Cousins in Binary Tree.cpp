/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sameParent(TreeNode *root,int x,int y)
    {
        if(root==NULL) return  false;
        if(root->left && root->right)
        {
            if((root->left->val==x && root->right->val==y) || (root->left->val==y &&       root->right->val==x))
            return true;
        }
        return sameParent(root->left,x,y) || sameParent(root->right,x,y);
    }
    
    bool sameLevel(TreeNode *root,int x,int y)
    {
        
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int level1=-1,level2=-1;
        while(!q.empty())
        {
            int size=q.size();
             
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                if(temp->val==x) level1=level;
                if(temp->val==y) level2=level;
                q.pop();
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(level1!=-1 && level1==level2) return true;
            level++;
        }
        return false;
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root==NULL) return false;
        bool parent=sameParent(root,x,y);
        if(parent) return !parent;
        return sameLevel(root,x,y);
    }
};