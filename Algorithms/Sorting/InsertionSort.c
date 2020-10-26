#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *a,int n)
{   int temp,j;
    for (int i = 1; i < n; i++)
    {
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
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
    insertionSort(arr,n);
    printf("\nArray After Sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}