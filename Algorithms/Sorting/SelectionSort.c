#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int a[],int n)
{   int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
            
        }
        swap(&a[min],&a[i]);
        
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
    selectionSort(arr,n);
    printf("\nArray After Selection Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}