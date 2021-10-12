#include<stdio.h>
#include<stdlib.h>

void ShellSort(int *a,int n)
{   
    for(int gap = n/2; gap>0; gap=gap/2)
    {
        for(int i=gap; i<n; i++)
        {
            int j=i;
            int key = a[j];
            while(j >= gap && a[j-gap] > key)
            {
                a[j] = a[j-gap];
                j=j-gap;
            }
            a[j]= key;
        }
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
    ShellSort(arr,n);
    printf("\nArray After Shell Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}