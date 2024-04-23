#include <stdio.h>
void multiply(int m1,int n1, double A[][n1], int m2,int n2,double B[][n2])
{
    int x, i, j;
    double C[m1][n2];
    for (int i = 0; i < m1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        C[i][j] = 0;
        for (int k = 0; k < m2; k++)
        {
          C[i][j] += A[i][k]*B[k][j];//calculating the value
        }
      }
    }
  printf("Resultant matrix is :\n");
  for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%0.02lf ", C[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
  int m1,m2,n1,n2,i,j;
  printf("Enter the dimensions of the first matrix\n");
  scanf("%d,%d",&m1,&n1);
  printf("Enter the dimensions of the second matrix\n");
  scanf("%d,%d",&m2,&n2);
  if(n1!=m2)//checking if multiplication is possible
    printf("Multiplication is not possible, no. of columns of A must be equal to the no. of rows of B");
  else
  {
    double A[m1][n1],B[m2][n2];
    printf("Enter the values in the matrice A row-wise\n");
    for(i=0;i<m1;i++)
    {  
      for(j=0;j<n1;j++)
      { 
        scanf("%lf",&A[i][j]);
      }
    }
    printf("Matrix A is :\n");
     for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            printf("%0.02lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("Enter the values in the matrice B row-wise\n");
    for(i=0;i<m2;i++)
    {  
      for(j=0;j<n2;j++)
      { 
        scanf("%lf",&B[i][j]);
      }
    }
    printf("Matrix B is :\n");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%0.02lf ", B[i][j]);
        }
        printf("\n");
    }
   multiply(m1, n1, A, m2, n2, B);
   }
  return 0;
}