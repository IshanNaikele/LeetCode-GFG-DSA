//Back-end complete function Template for C++

class Solution 
{
  public:
  
    int find(int inorder[], int start, int end, int val)
    {
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    bool check(int preorder[], int inorder[], int postorder[],
               int inStart, int inEnd,
               int preStart, int preEnd,
               int postStart, int postEnd)
    {
        if(inStart > inEnd)
            return true;

 
        if(preorder[preStart] != postorder[postEnd])
            return false;

        int rootVal = preorder[preStart];
        int pos = find(inorder, inStart, inEnd, rootVal);

        if(pos == -1)
            return false;

        int leftSize = pos - inStart;

         
        bool left = check(preorder, inorder, postorder,
                          inStart, pos-1,
                          preStart+1, preStart+leftSize,
                          postStart, postStart+leftSize-1);

         
        bool right = check(preorder, inorder, postorder,
                           pos+1, inEnd,
                           preStart+leftSize+1, preEnd,
                           postStart+leftSize, postEnd-1);

        return left && right;
    }
    
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    {
        // Your code goes here
        
        return check(preorder, inorder, postorder,
                     0, N-1,
                     0, N-1,
                     0, N-1);
    }
    
};

//Back-end complete function Template for C++

class Solution 
{
  public:
  
    int find(int inorder[], int start, int end, int val)
    {
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    Node* build(int preorder[], int inorder[],
                int inStart, int inEnd, int &preIndex)
    {
        if(inStart > inEnd) return NULL;

        Node* root = new Node(preorder[preIndex]);
        preIndex++;

        int pos = find(inorder, inStart, inEnd, root->data);

        root->left  = build(preorder, inorder, inStart, pos-1, preIndex);
        root->right = build(preorder, inorder, pos+1, inEnd, preIndex);

        return root;
    }
    
    void makePostorder(Node* root, vector<int> &res)
    {
        if(!root) return;

        makePostorder(root->left, res);
        makePostorder(root->right, res);
        res.push_back(root->data);
    }
    
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    {
        // Your code goes here
        
        int preIndex = 0;

         
        Node* root = build(preorder, inorder, 0, N-1, preIndex);

        vector<int> generatedPost;
        makePostorder(root, generatedPost);

         
        for(int i = 0; i < N; i++)
        {
            if(generatedPost[i] != postorder[i])
                return false;
        }

        return true;
    }
    
};