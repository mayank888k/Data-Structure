#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *newnode, *head=NULL, *tail, *temp;

void CreateList()
{
    int ch=1;
    while (ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter The data of New node\n");
        scanf("%d",&newnode->data);
        if (head==NULL)
        {
            head=newnode;
            temp=newnode;
            newnode->prev=NULL;
        }
        else
        {
            newnode->prev=temp;
            temp->next=newnode;
            temp=temp->next;
            temp->next=NULL;
            tail=temp;
        }

        printf("Want To Insert More Nodes Press 1\n");
        scanf("%d",&ch);
    }   
}

void DisplayList()
{   int i=1;
    temp=head;

    printf("Front Traversing\n");
    while (temp!=NULL)
    {   printf("Data of Node %d is %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
    i--;
    printf("Back Traversing\n");
    temp=tail;
    while (temp!=NULL)
    {
        printf("Data of Node %d is %d\n",i,temp->data);
        temp=temp->prev;
        i--;
    }
}

void insertBeg()
{   temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter The data of New node to be inserted at Begining\n");
    scanf("%d",&newnode->data);

    head->prev=newnode;
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;
}

void insertEnd()
{   temp=tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter The data of New node to be inserted at End\n");
    scanf("%d",&newnode->data);
    
    newnode->prev=tail;
    tail->next=newnode;
    newnode->next=NULL;
    tail=newnode;
}

void insertMid()
{   int info;
    temp=head;

    printf("enter the data before which you want to insert node\n");
    scanf("%d",&info);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter The data of New node to be inserted\n");
    scanf("%d",&newnode->data);

    while (temp->data!=info)
    {
        temp=temp->next;
    }

    newnode->next=temp;
    temp=temp->prev;
    newnode->prev=temp;
    temp->next=newnode;
    temp=temp->next->next;   //going from prev to newnode then to next
    temp->prev=newnode;

}

void delBeg()
{   struct node *del;
    temp=head;

    del=head;
    head=head->next;
    head->prev=NULL;

    printf("Deleted Beg Node data is %d\n",del->data);
    free(del);
}

void delEnd()
{   struct node *del;
    temp=tail;

    del=tail;
    tail=tail->prev;
    tail->next=NULL;
    
    printf("Deleted Beg Node data is %d\n",del->data);
    free(del);
}

void delMid()
{   int info;
    struct node *del;
    temp=head;
    printf("Enter the data of Node you want to delete\n");
    scanf("%d",&info);

    while (temp->data!=info)
    {
        temp=temp->next;
    }
    del=temp;
    temp=temp->prev;
    temp->next=temp->next->next;
    temp=temp->next;
    temp->prev=temp->prev->prev;
    printf("Deleted Node Data is %d",del->data);
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
            CreateList();
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
            DisplayList();
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