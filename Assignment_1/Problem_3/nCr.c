#include <stdio.h>
int fac(int x)
{ //recursive method to calculate factorial
  if (x==1||x==0) return 1;
  else return x*fac(x-1);
}
int main(void) {
  int n,r;
  double nCr=0.0;
  printf("Enter n and r\n");
  scanf("%d %d",&n,&r);
  if(r<0 || n<0)
  {
    printf("Neither n nor r must be negative\n");
  }
  else
  {
    if (r<=n) // r must be less than n for calculating nCr
    { 
      nCr=fac(n)/(fac(r)*fac(n-r));
      printf("The value of nCr is %0.2lf",nCr);
    }
    else printf("r must be less or equal to than n");
      return 0;
  }  
}