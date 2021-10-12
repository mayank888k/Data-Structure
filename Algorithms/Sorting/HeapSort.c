#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *a, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && a[l] > a[largest])
    {
        largest = l;
    }

    if(r<n && a[r] > a[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void Build_Max_Heap(int *a, int n)
{
    for(int i= n/2-1; i>0; i--)
    {
        heapify(a, n, i);
    }
}

void HeapSort(int *a, int n)
{
    Build_Max_Heap(a, n);

    for(int i = n-1; i>=0; i--)
    {
        swap(&a[i], &a[0]);
        heapify(a, i, 0);
    }
}

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
    HeapSort(arr,n);
    printf("\nArray After Heap Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}