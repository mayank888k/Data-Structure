#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *newnode, *head=NULL, *temp;

void createList()
{ int ch=1;
    while (ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of new node\n");
        scanf("%d",&newnode->data);

        if (head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
            temp->next=head;
        }
        printf("Want to Insert more node Press 1\n");
        scanf("%d",&ch);
    }
}

void Display()
{ int i=2;
    temp=head;
    printf("Data Of Node 1 is %d\n",temp->data);
    temp=temp->next;

    while (temp!=head)
    {
        printf("Data of Node %d is %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}

void insertBeg()
{   temp=head;

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of new node to be inserted at the Begining\n");
    scanf("%d",&newnode->data);

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
}

void insertEnd()
{
    temp=head;

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of new node to be inserted at the End\n");
    scanf("%d",&newnode->data);

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}

void insertMid()
{   int info;
    temp=head;

    printf("Enter the node data after which you want to insert node\n");
    scanf("%d",&info);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of new node to be inserted at the End\n");
    scanf("%d",&newnode->data);

    while(temp->data!=info)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void delBeg()
{   struct node *del;
    temp=head;
    temp=temp->next;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    del=head;
    head=head->next;
    printf("Deleted Node data is %d\n",del->data);
    free(del);
}

void delEnd()
{   struct node *del, *prevtemp;
    temp=head;
    temp=temp->next;
    while (temp->next!=head)
    {   
        prevtemp=temp;
        temp=temp->next;
    }
    prevtemp->next=head;
    del=temp;
    printf("Deleted Node data is %d\n",del->data);
    free(del);
}

void delMid()
{   struct node *del, *prevtemp;
    int info;
    printf("Enter the Data of Node you want to delete\n");
    scanf("%d",&info);
    temp=head;
    temp=temp->next;
    while (temp->data!=info)
    {   
        prevtemp=temp;
        temp=temp->next;
    }
    prevtemp->next=temp->next;
    del=temp;
    printf("Deleted Node data is %d\n",del->data);
    free(del);
}

int main()
{   int ch=0;

    while (ch!=9)
    {
        printf("\nWhat do you Want\n");
        printf("1 Create a link list\n");
        printf("2 Insert Node at Begining\n");
        printf("3 Insert Node at the END\n");
        printf("4 Insert Node in the Middle\n");
        printf("5 Delete Node in the Begining\n");
        printf("6 Delete Node in the END\n");
        printf("7 Delete Node in the Middle\n");
        printf("8 Display the link list\n");
        printf("9 Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            createList();
            break;
        case 2:
            insertBeg();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertMid();
            break;
        case 5:
            delBeg();
            break;
        case 6:
            delEnd();
            break;
        case 7:
            delMid();
            break;
        case 8:
            Display();
            break;
        case 9:
            break;
        default:
            printf("\nwronge choice\n");
            break;
        }
        
    }
    
    return 0;
}

