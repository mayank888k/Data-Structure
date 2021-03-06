#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create()
{   
    int x;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n\nEnter the Data of the node (Press -1 if Dont want to insert) :");
    scanf("%d",&x);
    if (x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Enter the left of %d",x);
    newnode->left=create();
    printf("Enter the right of %d",x);
    newnode->right=create();
    return newnode;
    
}

void inorder(struct node* root)
{   
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d ->",root->data);
    inorder(root->right);
}
void postorder(struct node* root)
{   
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ->",root->data);
}
void preorder(struct node* root)
{   
    if (root==NULL)
    {
        return;
    }
    printf(" %d ->",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node* root;
    root=create();
    printf("\n\nInorder Traversal is :");
    inorder(root);
    printf("\n\nPreorder Traversal is :");
    preorder(root);
    printf("\n\nPostorder Traversal is :");
    postorder(root);
}