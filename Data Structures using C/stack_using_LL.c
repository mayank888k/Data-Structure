#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *newnode, *stack=NULL, *top, *temp, *prevtemp;

void push();
void pop();
void display();

int main()
{int ch=0;
    while(ch!=4)
    {
        printf("\nWhat do you Want\n");
        printf("1 Push In Stack\n");
        printf("2 Pop in Stack\n");
        printf("3 Display Stack\n");
        printf("4  Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&ch);
         switch (ch)
         {
         case 1:
             push();
             break;
         case 2:
             pop();
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

void push()
{
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("Enter Element of Stack: ");
    scanf("%d",&newnode->data);

    if (stack==NULL)
    {
        stack=newnode;
        top=newnode;
    }
    else
    {
        top->next=newnode;
        top=top->next;
        top->next=NULL;
    }
    
}

void pop()
{   temp=stack;
if (stack==NULL)
{
    printf("Stack is Empety");
}

else
{

    while(temp->next!=NULL)
    {   
        prevtemp=temp;
        temp=temp->next;
    }
    top=prevtemp;
    top->next=NULL;
    printf("%d is Poped from the Stack",temp->data);
}
}

void display()
{
    temp=stack;
    printf("Stack is\n\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}