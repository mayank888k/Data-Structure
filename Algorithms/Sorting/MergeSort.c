#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1],R[n2];

    int i,j,k;

    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid+1+i];
    }

    i=0;
    j=0;
    k=low;

    while (i<n1 && j<n2)
    {
        if (L[i]<R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    while (i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    } 
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low<high)
    {
        mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergeSort(arr,0,n-1);
    printf("\nArray After Merge Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}