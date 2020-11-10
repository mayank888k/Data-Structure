#include<stdio.h>
#include<stdlib.h>

void inint(int a[][100],int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j]=0;
        }
    }
}

void addEdge(int a[][100],int src, int dest)
{
    a[src-1][dest-1]=1;
}

void printAM(int a[][100], int v)
{   
    printf("\nAdjacency Matrix Is :\n\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    int a[100][100], v, src, dest, c;
    printf("Enter the number of vertices of the graph :");
    scanf("%d",&v);
    inint(a,v);
    while (c!=3)
    {   
        printf("\nPress 1 to Add Edge of the Graph\n");
        printf("Press 2 to Print Adjacency Matric\n");
        printf("Press 3 to Exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("\nEnter The Source and Destination :");
            scanf("%d%d",&src,&dest);
            addEdge(a,src,dest);
            break;
        case 2:
        printAM(a,v);
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    
    return 0;
}