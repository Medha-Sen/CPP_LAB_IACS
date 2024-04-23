#include <stdio.h>
#include<stdlib.h>
int main(void) {
int n,m,i,j;
printf("Enter the values of m and n\n");
  scanf("%d,%d",&m,&n);
  double **DynamicMatrix =(double**)malloc(m*sizeof(double*));//allocating memory
  for (int i = 0; i < m; i++)
   DynamicMatrix[i] = (double*) malloc(n*sizeof(double));
  printf("Enter the values in the matrice row-wise\n");
  for(i=0;i<m;i++)
  {  
    for(j=0;j<n;j++)
      { 
        scanf("%lf",&DynamicMatrix[i][j]);
      }
  }
  double sumr=0.0,sumc=0.0;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
      {
        printf("%0.02lf,",DynamicMatrix[i][j]);
      }
    printf("\n");
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
      {
        sumr=sumr+DynamicMatrix[i][j];//row-wise sum
      }
    printf("sum of row %d is %0.02lf\n",i+1,sumr);
    sumr=0.0;
  }
  for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
      {
        sumc=sumc+DynamicMatrix[j][i];//column-wise sum
      }
    printf("sum of column %d is %0.02lf\n",i+1,sumc);
    sumc=0.0;
  }
}