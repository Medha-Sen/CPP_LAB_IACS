#include<stdio.h>
#include<math.h>
double func(double x)
{
  return (1/(x+1)); //function defined
}
int main()
{
 double l, u, integ=0.0, step, k;
 int i;
 printf("Enter lower limit of integration: ");
 scanf("%lf", &l);
 printf("Enter upper limit of integration: ");
 scanf("%lf", &u);
 if(l>u)
 {
   printf("Lower limit must be less than upper limit\n");
 }
else
 {
  step= (u - l)/1000;
 integ = func(l) + func(u);
 for(i=1; i<1000; i++)//Simpson method of integration
 {
  k = l + i*step;
  if(i%2==0)
  {
   integ = integ + 2 * func(k);
  }
  else
  {
   integ = integ + (4 * (func(k)));
  }
 }
 integ = integ * step/3;
 printf("\nRequired value of integration is: %.3f", integ);
 }
 
 return 0;
}