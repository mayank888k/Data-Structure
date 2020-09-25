#include<stdio.h>
#include<stdlib.h>

#define max 10

int queue[max];
int front=-1;
int rear=-1;

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
{int data;
    if (rear==max-1)
    {
        printf("Owerflow");
    }
    else
    {   
        if (front==-1)
        {
            front=0;
        }
        printf("Enter Element of Queue : ");
        scanf("%d",&data);
        rear=rear+1;
        queue[rear]=data;
    }
    
}

void delete()
{int data;
    if(front==-1)
    {
        printf("Underflow");
    }
    else
    {   data=queue[front];
        front=front+1;
        printf("%d is deleted\n",data);
    }
    
}

void display()
{   printf("\nQueue is\n\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    
}