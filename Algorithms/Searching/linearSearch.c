#include<stdio.h>
#include<stdlib.h>

int lsearch(int a[],int n,int item)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i]==item)
        {
            return i;
        }
    }
    return -1;
    
}

int main()
{
    int arr[20],n,item,index;
    printf("Enter the size of array :");
    scanf("%d",&n);

    printf("Enter the Elements of Array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\nEnter the Element to be searched in Array :");
    scanf("%d",&item);

    index = lsearch(arr,n,item);
    if (index==-1)
    {
        printf("\nElement Not Found in Array");
    }
    else
    {
        printf("\nElement Found at Position %d",index+1);
    }
    
    return 0;
    
}