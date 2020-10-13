#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("Move Disc from Peg %c to %c \n",from,to);
        return;
    }
    towerOfHanoi(n-1,from,aux,to);
    printf("Move Disc from Peg %c to %c \n",from,to);
    towerOfHanoi(n-1,aux,to,from);

}

int main()
{
    int n;
    printf("Enter The umber of Disc in Peg A\n");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');

}