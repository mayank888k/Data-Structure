#include<stdio.h>

void insert(int a[], int *n)
{   
    int data, pos;
    printf("\nEnter the data to be Inserted and its Position :");
    scanf("%d %d",&data,&pos);
    for (int i = *n ; i >=pos; i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=data;
    *n=*n+1;
}

void delete(int a[], int *n)
{
    int pos;
    printf("\nEnter the position of element to be deleted :");
    scanf("%d",&pos);

    for (int  i = pos-1; i < *n; i++)
    {
        a[i]=a[i+1];
    }
    *n=*n-1;
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}
int main()
{ int a[100], n, ch=0;

printf("Enter the size of array :\n");
scanf("%d",&n);

printf("Enter the elements of array :\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]); 
}

 while(ch!=4)
 {
   printf("\nMenu:\n");
   printf("1 : Insert Element in Array\n");
   printf("2 : Delete Element in Array\n");
   printf("3 : Display Array\n");
   printf("4 : exit\n");
   
   scanf("%d",&ch);
   
   switch (ch)
   {
   case 1:
     insert(a,&n);
     break;
   case 2:
     delete(a,&n);
     break;
   case 3:
     display(a,n); 
     break;
   case 4:
     break;
   }

 }
  return 0;
}