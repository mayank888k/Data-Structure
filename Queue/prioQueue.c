#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int pri;
    struct node *next;
}*newnode, *temp, *head=NULL, *prev=NULL;

void createQueue()
{
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter data of Newnode\n");
    scanf("%d",&newnode->data);
    printf("Enter Priority of Newnode\n");
    scanf("%d",&newnode->pri);

    if (head==NULL)
    {
        head=newnode;
        temp=newnode;
        newnode->next=NULL;
    }
    else
    {   
        if (head->pri>newnode->pri)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
        
        temp=head;
        while(temp->next!=NULL && (temp->next->pri<= newnode->pri))
        {   
           temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        }
    }
}

void delete()
{   struct node *del;
    temp=head;
    while(temp->next!=NULL)
    {   
        prev=temp;
        temp=temp->next;
    }
    del=temp;
    prev->next=NULL;

    printf("\n%d is Deleted from END of Link list\n",del->data);
    free(del);
}
void display()
{   int i=1;
    temp=head;
    printf("\nDisplaying Your Queue\n");
    while (temp!=NULL)
    {
        printf("Data of Node %d is %d and priority is %d \n", i, temp->data, temp->pri);
        temp=temp->next;
        i++;
    }
    
}

int main()
{int ch=0;
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
             createQueue();
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