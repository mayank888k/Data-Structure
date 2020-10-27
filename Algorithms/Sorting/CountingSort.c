#include<stdio.h>
#include<stdlib.h>

void countSort(int a[],int n, int k)
{
    int count[k+1];
    int b[n];
    
    for (int i = 0; i < k+1; i++)
    {
        count[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i < k+1; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        b[--count[a[i]]]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=b[i];
    }
}

int main()
{
    int arr[20],n,max;
    printf("Enter the size of array :");
    scanf("%d",&n);

    printf("Enter the Elements of Array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray Before Sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

    max=arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    
    countSort(arr,n,max);
    printf("\nArray After Counting Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}