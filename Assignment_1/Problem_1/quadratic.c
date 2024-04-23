#include <stdio.h>
#include<math.h>
//defining the range of values to be considered as being  equal to 0
#define e 0.0000001
void quad_root(double a,double b,double c)
{
  double x1=0.0,x2=0.0;
  double d=(b*b)-(4*a*c);//calculating the discriminant
  if (fabs(d)<e) printf("No real valued roots");// (-)ve discriminant indicates complex valued roots
  else
  { if(fabs(a)>e)
    {
      if(fabs(d)<e) printf("Roots are equal and value is %0.2lf",(-b/(2*a)));// Zero discriminant indicates equal roots
      else // Positive and non-zero discriminant indicates real and distinct roots
      { x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("Roots are %0.2lf and %0.2lf",x1,x2);
      }
    }
    else printf("Not a quadratic equation");// Quadratic equation always has highest degree 2
  }
}
int main() {
  double a,b,c;
  printf("Enter the values of the coefficients (a,b,c)\n");
  scanf("%lf, %lf ,%lf",&a,&b,&c);
  quad_root(a,b,c);
}