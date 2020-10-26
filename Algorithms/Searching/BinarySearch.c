#include<stdio.h>
#include<stdlib.h>

int Bsearch(int a[],int n,int item)
{
    int beg, end, mid;
    beg = 0;
    end = n-1;

    while (beg<end)
    {
        mid = (beg + end)/2;
        if (item<a[mid])
        {
            end=mid-1;
        }
        else if (item>a[mid])
        {
            beg=mid+1;
        }
        else if (a[mid]==item)
        {
            return mid;
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

    index = Bsearch(arr,n,item);
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