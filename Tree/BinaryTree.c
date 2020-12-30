#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* root=NULL;

struct node* createNode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct node *insertLeft(struct node *root, int data)
{
    root->left=createNode(data);
    return root->left;
}
struct node *insertRight(struct node *root, int data)
{
    root->right=createNode(data);
    return root->right;
}

void inorderTraversal(struct node* root)
{
    if (root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ->",root->data);
    inorderTraversal(root->right);
    
}

void preorderTraversal(struct node* root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%d ->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

void postorderTraversal(struct node* root)
{
    if (root==NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->",root->data);
    
}

int main()
{   /* Binary Tree is 
                1
                /\
               /  \
              /    \
             2       3              
            /\       /\
           /  \     /  \
          4    5   6    7   
          
                                  */ 
    root=createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);
    insertRight(root->left,5);
    insertLeft(root->right,6);
    insertRight(root->right,7);

    printf("\n\nInorder Trversal Is ");
    inorderTraversal(root);
    printf("\n\nPreorder Trversal Is ");
    preorderTraversal(root);
    printf("\n\nPostorder Trversal Is ");
    postorderTraversal(root);
    printf("\n\n");
    return 0;
}