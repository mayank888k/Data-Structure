#include<stdio.h>
#include<stdlib.h>

int getMax(int a[],int n)
{
    int max=a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}

void countSort(int a[],int n, int pos)
{
    int count[10]={0};
    int b[n];

    for (int i = 0; i < n; i++)
    {
        count[(a[i]/pos)%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (int i = n-1; i>=0; i--)
    {
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=b[i];
    } 
}

void radixSort(int a[],int n)
{
    int max=getMax(a,n);
    for (int pos = 1; max/pos>0; pos=pos*10)
    {
        countSort(a,n,pos);
    }
    
}

int main()
{
    int arr[20],n;
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
    radixSort(arr,n);
    printf("\nArray After Radix Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}