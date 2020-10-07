#include<stdio.h>
#include<stdlib.h>

#define max 10
int stack[max], top=-1;

void push();
void pop();
void display();

int main()
{int ch=0;
    while(ch!=4)
    {
        printf("\nWhat do you Want\n");
        printf("1 Push In Stack\n");
        printf("2 Pop in Stack 2\n");
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
    int data;
    printf("Enter Data to be inserted\n");
    scanf("%d",&data);
    if (top==max-1)
    {
        printf("Stack Is Full\n");
    }
    else
    {   
        top=top+1;
        stack[top]=data;
    }
}

void pop()
{   int del;
    if (top==-1)
    {
        printf("Stack is Empety\n");
    }
    else
    {
        del=stack[top];
        top=top-1;
        printf("Deleted element is %d",del);   
    }
}

void display()
{   int i=top;
    printf("\nDisplaying From Top to Bottom\n");
    for (i ; i >=0; i--)
    {
        printf("%d\t",stack[i]);
    }
    printf("\nDisplaying From Bottom to Top\n");
    for ( i= 0; i<=top; i++)
    {
        printf("%d\t",stack[i]);
    }
}
