#include <stdio.h>
#include<math.h>
#define e 0.00001
int fac(int x)
{
  if (x==1||x==0) return 1;
  else return x*fac(x-1);
}
double series(double x)
{
  double sum=x,temp=x;
  int k=3,s=-1;
  while(fabs(temp)>e)//condition for terminating the series
  { temp=pow(x,k)/fac(k);
    sum=sum+(s*temp);      
    k=k+2;
    s=s*(-1);
  }
  return sum;
}
int main(void) {
  double x;
  printf("Enter the value for x\n");
  scanf("%lf",&x);
  if(fabs(x)>2)// for large x
    printf("Sum of series is %0.5lf",sin(x));
  // The above series is the expansion of sinx for small value of x
  else
   printf("Sum of series is %0.5lf",series(x));
  return 0;
}