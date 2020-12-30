#include<stdio.h>
#include<stdlib.h>
 
int DepthFirstSearch(int);
 
int n;
 
int graph[20][20], completed[10];
 
int DepthFirstSearch(int i)
{
    int j;
 
      printf("\n%d", i);
 
    completed[i] = 1;
 
      for(j=0;j<n;j++)
    {
        if(!completed[j] && graph[i][j] == 1)
        {
            DepthFirstSearch(j);
        }
    }
 
    return 0;
}
 
int main()
{
    int i, j, src;
 
    printf("\nEnter number of vertices:");
 
    scanf("%d",&n);
 
    printf("\nEnter adjecency matrix :\n");
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
               scanf("%d",&graph[i][j]);
        }
    } 
    printf("\n Adjacency Matrix is :\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
               printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the source node : ");
    scanf("%d",&src);
 
   for(i=0;i<n;i++)
    {
        completed[i]=0;
    }
    printf("\nDepth First Search is :\n");
 
    DepthFirstSearch(src);
 
    return 0;
}