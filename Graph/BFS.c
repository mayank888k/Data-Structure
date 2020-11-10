#include<stdio.h>

int a[20][20], q[20], visited[20], v, s, f=0, r=-1;

void bfs(int s)
{
    for (int i = 0; i < v; i++)
    {
        if (a[s][i] && !visited[i])
        {
            q[++r]=i;   
        }
        if (f<=r)
        {   
            visited[q[f]]=1;
            bfs(++f);
        }
    }
}

int main()
{
    printf("Enter the number of Vertices of Graph :");
    scanf("%d",&v);

    for (int i = 0; i < 20; i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    
    printf("Enter the Adjacency Matrix : ");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nAdjacency Matrix Is :\n\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the Source Node : ");
    scanf("%d",&s);
    bfs(s-1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i])
        {
            printf("Node %d is visited\n",i+1);
        }
        else
        {
            printf("BFS is not possible, Node %d can't be visited\n",i+1);
        }
    }
}