#include<stdio.h>

void add(int a[10][10], int b[10][10], int m, int n, int p, int q);
void sub(int a[10][10], int b[10][10], int m, int n, int p, int q);
void mult(int a[10][10], int b[10][10], int m, int n, int p, int q);
void trans(int a[10][10],int m, int n);
void rsmcsm(int a[10][10],int m, int n);

int main()
{ int a[10][10],b[10][10],m,n,p,q,ch;

printf("Enter the rows and column of 1st Matrix\n");
scanf("%d%d",&m,&n);

printf("Enter the elements of 1st matrix\n");
for(int i=0;i<m;i++)
{
  for (int j = 0; j < n; j++)
  {
    scanf("%d",&a[i][j]);
  }
  
}
printf("Enter the rows and column of 2nd Matrix\n");
scanf("%d%d",&p,&q);

printf("Enter the elements of 2nd matrix\n");
for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    scanf("%d",&b[i][j]);
  }
  
}
printf("\nMatrix 1 is\n\n");
for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    printf("%d\t",a[i][j]);
  }
  printf("\n");
  
}
printf("\nMatrix 2 is\n\n");
for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    printf("%d\t",b[i][j]);
  }
  printf("\n");
}
 while(ch!=6)
 {
   printf("\nMenu:\n");
   printf("1 : Matrix Addition\n");
   printf("2 : Matrix Subtraction\n");
   printf("3 : Matrix Multiplication\n");
   printf("4 : Matrix Transpose\n");
   printf("5 : Matrix Rowwise and Columnwise Sum\n");
   printf("6 : exit\n");
   
   scanf("%d",&ch);
   
   switch (ch)
   {
   case 1:
     add(a,b,m,n,p,q);
     break;
   case 2:
     sub(a,b,m,n,p,q);
     break;
   case 3:

     if(n!=p)
     {
       printf("Multiplication can,t be possible\n");
     }
     else{
     mult(a,b,m,n,p,q);}
     break;
   case 4:
     trans(a,m,n);
     break;
   case 5:
     rsmcsm(a,m,n);
     break;
   case 6:
     break;
   }

 }
  return 0;
}



void add(int a[10][10], int b[10][10], int m, int n, int p, int q)
{
  int c[10][10];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      c[i][j]=a[i][j]+b[i][j];
    }
  }

  printf("\nAddition of Matrix 1 and 2 is:\n");
  for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    printf("%d\t",c[i][j]);
  }
  printf("\n");
}
}



void sub(int a[10][10], int b[10][10], int m, int n, int p, int q)
{
   int c[10][10];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      c[i][j]=a[i][j]-b[i][j];
    }
  }

  printf("\nSubtraction of Matrix 1 and 2 is:\n");
  for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    printf("%d\t",c[i][j]);
  }
  printf("\n");
}
}


void mult(int a[10][10], int b[10][10], int m, int n, int p, int q)
{
  int c[10][10];
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<q; j++)
    { 
      c[i][j]=0;
      for(int k=0; k<n; k++)
      {
        c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
      }
    }
  }

  printf("\nMultiplication of Matrix 1 and 2 is:\n");
  for(int i=0;i<p;i++)
{
  for (int j = 0; j < q; j++)
  {
    printf("%d\t",c[i][j]);
  }
  printf("\n");
}
}


void trans(int a[10][10],int m, int n)
{
  int c[10][10];
  for( int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      c[i][j]=a[j][i];
    }
  }

  printf("\nTranspose of Matrix 1 is:\n");
  for(int i=0;i<m;i++)
{
  for (int j = 0; j < n; j++)
  {
    printf("%d\t",c[i][j]);
  }
  printf("\n");
}
}



void rsmcsm(int a[10][10],int m, int n)
{
  int rowsum=0, columnsum=0;
  for(int i=0; i<m; i++)
  { 
    rowsum=0;
    columnsum=0;

    for(int j=0; j<n; j++)
    {
      rowsum+=a[i][j];
      columnsum+=a[j][i];
    }
    printf("Sum of elements of row %d is %d\n",i+1,rowsum);
    printf("Sum of elements of column %d is %d\n",i+1,columnsum);
  }
}






