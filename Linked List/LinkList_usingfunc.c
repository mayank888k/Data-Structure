#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *newnode, *head=NULL, *temp, *prevtemp;

void CreateList();
void DisplayList();
void insertBeg();
void insertEnd();
void insertMid();
void delBeg();
void delEnd();
void delMid();


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

void CreateList()
{
    int ch=1;
    while (ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data of new Node\n");
        scanf("%d",&newnode->data);

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
            temp->next=NULL;
        }

        printf("\nWant to Enter more Nodes Press 1 If Not Press 0\n");
        scanf("%d",&ch);
    }
    temp=head;
}

void DisplayList()
{   int i=1;
    temp=head;
    printf("\nDisplaying Your LinkList\n");
    while (temp!=NULL)
    {
        printf("Data of Node %d is %d\n", i, temp->data);
        temp=temp->next;
        i++;
    }
    
}

void insertBeg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data of new node inserting at begining\n");
    scanf("%d",&newnode->data);

    newnode->next=head;
    head=newnode;

    printf("\nNew Node is inserted at the Begining.....\n");

}

void insertEnd()
{
    temp=head;

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data of new node inserting at END\n");
    scanf("%d",&newnode->data);
    
    while(temp->next!=NULL)
    {
       temp=temp->next;
    }
   temp->next=newnode;
   newnode->next=NULL;

   printf("\nNew Node is inserted at the END.....\n");
}

void insertMid()
{   int da;
    temp=head;
    printf("\nEnter the data of node after whose new node is to be inserted\n");
    scanf("%d",&da);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data of new node inserting at Middle\n");
    scanf("%d",&newnode->data);

    while(temp->data!=da)
    {
        //prevtemp=temp;
        temp=temp->next;
    }
    //prevtemp->next=newnode;  //for inserting before
    //newnode->next=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    printf("\nNew Node is inserted after %d\n",da);
}

void delBeg()
{   struct node *del;
    del=head;
    head=head->next;
    printf("%d is Deleted from Begining of Link list",del->data);
    free(del);
}

void delEnd()
{   struct node *del;
    temp=head;
    while(temp->next!=NULL)
    {   
        prevtemp=temp;
        temp=temp->next;
    }
    del=temp;
    prevtemp->next=NULL;

    printf("\n%d is Deleted from END of Link list\n",del->data);
    free(del);
}

void delMid()
{   
    int da;
    struct node *del;
    temp=head;
    printf("\nEnter the data whose node is to be deleted\n");
    scanf("%d",&da);

    while(temp->data!=da)
    {
        prevtemp=temp;
        temp=temp->next;
    }
    prevtemp->next=temp->next;
    del=temp;
    printf("\n%d is Deleted from Middle of Link list\n",del->data);
    free(del);

}  