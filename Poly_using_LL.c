#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
} *newnode, *head=NULL, *temp, *newpoly, *poly1, *poly2, *sum=NULL;

void createPoly()
{ int ch=1;

    while(ch==1)
    {   
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Coeff first then its Exponent \n");
        scanf("%d %d",&newnode->coeff,&newnode->exp);
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
        printf("Want To Add More Term Press 1\n");
        scanf("%d",&ch);
    }
}

void AddPoly()
{
    createPoly();
    newpoly=head;
    head=NULL;
}
void Display( struct node* poly)
{int i=1;
    temp=poly;

    while (temp!=NULL)
    {
        printf("%d Term : Coeff = %d Exponent = %d\n",i,temp->coeff,temp->exp);
        temp=temp->next;
        i++;
    }
    
}
void AddBoth(struct node* poly1, struct node *poly2)
{
    while(poly1!=NULL || poly2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (sum==NULL)
        {
            sum=newnode;
            temp=newnode;
            if (poly1->exp==poly2->exp)
            {
                temp->coeff=poly1->coeff+poly2->coeff;
                temp->exp=poly1->exp;
            }
            else if (poly1->exp==0)
            {
                temp->coeff=poly2->coeff;
                temp->exp=poly2->exp;
            }
            else if (poly2->exp==0)
            {
                temp->coeff=poly1->coeff;
                temp->exp=poly1->exp;
            }
        }
        else
        {
            if (poly1->exp==poly2->exp)
            {
                newnode->coeff=poly1->coeff+poly2->coeff;
                newnode->exp=poly1->exp;
                temp->next=newnode;
                temp=temp->next;
                temp->next=NULL;
            }
            else if (poly1->exp==0)
            {
                newnode->coeff=poly2->coeff;
                newnode->exp=poly2->exp;
                temp->next=newnode;
                temp=temp->next;
                temp->next=NULL;

            }
            else if (poly2->exp==0)
            {
                newnode->coeff=poly1->coeff;
                newnode->exp=poly1->exp;
                temp->next=newnode;
                temp=temp->next;
                temp->next=NULL;

            }
        }
     poly1=poly1->next;
     poly2=poly2->next;
    }
}
int main()
{
int ch=0;

    while (ch!=7)
    {
        printf("\nWhat do you Want\n");
        printf("1 Create Polynomial 1\n");
        printf("2 Create Polynomial 2\n");
        printf("3 Add Both Polynomial\n");
        printf("4 Display Polynomial 1\n");
        printf("5 Display Polynomial 2\n");
        printf("6 Display Sum of Both Polynomial\n");
        printf("7 Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            AddPoly();
            poly1=newpoly;
            break;
        case 2:
            AddPoly();
            poly2=newpoly;
            break;
        case 3:
            AddBoth(poly1,poly2);
            break;
        case 4:
            printf("\nPolynomial 1 is\n");
            Display(poly1);
            break;
        case 5:
            printf("\nPolynomial 2 is\n");
            Display(poly2);
            break;
        case 6:
            printf("\nSum of Both Polynomial is\n");
            Display(sum);
            break;
        case 7:
            break;
        default:
            printf("\nwronge choice\n");
            break;
        }
        
    }
    
    return 0;
}


