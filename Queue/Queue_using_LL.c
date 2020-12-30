#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *front =NULL;
struct node *rear =NULL;

void insert();
void delete();
void display();

int main()
{int ch=0;
    while(ch!=4)
    {
        printf("\nWhat do you Want\n");
        printf("1 Insert In Queue\n");
        printf("2 Delete From Queue\n");
        printf("3 Display Queue\n");
        printf("4  Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&ch);
         switch (ch)
         {
         case 1:
             insert();
             break;
         case 2:
             delete();
             break;
         case 3:
             display();
             break;
         case 4:
             break;
         
         default:
             printf("Wrong Choice\n");
             break;
         }
    }
    return 0;
}

void insert()
{
    int data;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted in queue :");
    scanf("%d",&data);
    newnode->data=data;
    
    if (front == NULL)
    {
        front=newnode;
        rear=newnode;
        front->next=NULL;
    }
    else
    {
        rear->next=newnode;
        rear=rear->next;
        rear->next=NULL;
    }
}

void delete()
{   
    if(front == NULL)
    {
        printf("\nQueue is Empety");
    }
    else
    {   struct node* temp =front;
        printf("\n%d is deleted from the queue",front->data);
        front=front->next;
        free(temp);
    }
}

void display()
{struct node* temp = front;

    printf("\nQueue is :\n\n");
    if(front==NULL)
    {
        printf("\nQueue is Empety");
        return;
    }
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

