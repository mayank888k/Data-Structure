#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{   
    struct node *newnode, *head=NULL, *temp;
    int ch=1,i=1;

    while(ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of newnode\n");
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

        printf("Want to create more nodes Press 1\n");
        scanf("%d",&ch);

    }
    temp=head;

    printf("\nDisplaying Your Link List\n");
    while (temp!=NULL)
    { 
        printf("Data of Node %d is = %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
    
    return 0;
}

