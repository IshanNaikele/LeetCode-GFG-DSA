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

Node *BinaryTree( )
{
    int x;
    cin>>x;
    if(x==-1) return NULL;
    Node *temp=new Node(x);
    cout<<"Enter the Left Node of "<<temp->data<<" :";
    temp->left=BinaryTree();
    cout<<"Enter the Right Node of "<<temp->data<<" :";
    temp->right=BinaryTree();
    return temp;
};

void preOrder(Node *root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if(root==NULL) return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if(root==NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    cout<<"Enter the root Node :";
    Node *root=BinaryTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}
