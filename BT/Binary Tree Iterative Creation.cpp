#include<iostream>
#include<queue>
using namespace std;

class Node 
{
    public:
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        right=left=NULL;
    }
};

class BinaryTree
{
    public:
    Node* root;   
    int first,second;
    queue<Node*>q;
    BinaryTree()
    {
        int rootValue;
        cout<<"Enter the Root Node :";
        cin>>rootValue;
        root=new Node(rootValue);
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            cout<<"Enter the left Child of "<<temp->data<<" :";
            cin>>first;
            cout<<"Enter the Right Child of "<<temp->data<<" :";
            cin>>second;
            if(first!=-1)
            {
                Node *newNode=new Node(first);
                temp->left=newNode;
                q.push(newNode);
            }
            if(second!=-1)
            {
                Node *newNode=new Node(second);
                temp->right=newNode;
                q.push(newNode);
            }
        }
    }
    
    void preOrder(Node *root)
    {
        if(root==NULL) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main()
{
    BinaryTree bt;          
    cout << "Preorder Traversal: ";
    bt.preOrder(bt.root);     
    return 0;
    return 0;
}

