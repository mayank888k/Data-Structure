#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    else
    {
        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int data)
{

    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int ch = 0, data;
    while (ch != 4)
    {
        printf("\nMenu:\n");
        printf("1 : Insert Element in Binary Search Tree\n");
        printf("2 : Delete Element in Binary Search Tree\n");
        printf("3 : Display Inorder Traversal of Binary Search Tree\n");
        printf("4 : Exit\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the data element to be inserted in BST :");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data element to be deleted in BST :");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("\nInorder Traversal of BST is :\n");
            inorder(root);
            break;
        case 4:
            break;
        }
    }

    return 0;
}