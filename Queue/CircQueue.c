#include<stdio.h>
#include<stdlib.h>

#define max 5

int cirQueue[max];
int front=-1;
int rear=-1;

void enqueue()
{   if (front == (rear+1)%max)
    {
        printf("\nOverflow");        
    }

    else
    {
        int data;
        printf("Enter the Data to Be inserted in the Queue\n");
        scanf("%d",&data);
        if (front==-1)
        {
            front=0;
        }
        
        rear=(rear+1)%max;
        cirQueue[rear]=data;
    }

}

void dequeue()
{
    if (front==-1 )
    {
        printf("\nUnderflow");
    }
    else if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
    
    
}

void display()
{  

    if (rear>=front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t",cirQueue[i]);
        }
    }
    else
    {
        for (int i = front; i < max; i++)
        {
            printf("%d\t",cirQueue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t",cirQueue[i]);
        }
        
    }
    
}
int main()
{
    int ch=0;
    while(ch!=4)
    {
        printf("\nWhat do you Want\n");
        printf("1 Insert In Queue\n");
        printf("2 Delete From Queue\n");
        printf("3 Display Queue\n");
        printf("4 Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&ch);
         switch (ch)
         {
         case 1:
             enqueue();
             break;
         case 2:
             dequeue();
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