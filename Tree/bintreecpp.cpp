#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

node* create()
{   
    int x;
    node* newnode;
    newnode=new node;
    cout<<"\n\nEnter the Data of the node (Press -1 if Dont want to insert) :"<<endl;
    cin>>x;
    if (x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    cout<<"Enter the left of "<<x<<endl;
    newnode->left=create();
    cout<<"Enter the right of "<<x<<endl;
    newnode->right=create();
    return newnode;
    
}

void inorder(node* root)
{   
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}
void postorder(node* root)
{   
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";
}
void preorder(node* root)
{   
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node* root;
    root=create();
    cout<<"\n\nInorder Traversal is :"<<endl;
    inorder(root);
    cout<<"\n\nPreorder Traversal is :"<<endl;
    preorder(root);
    cout<<"\n\nPostorder Traversal is :"<<endl;
    postorder(root);
}