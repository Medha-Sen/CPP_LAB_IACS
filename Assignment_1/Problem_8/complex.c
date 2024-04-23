#include <stdio.h>
#include<stdlib.h>
typedef struct{ double real;double imag;}COMPLEX;
COMPLEX add(COMPLEX c1,COMPLEX c2)
{
  COMPLEX c3;
  c3.real=c1.real+c2.real;//adding the real part
  c3.imag=c1.imag+c2.imag;//adding the imaginary part
  return c3;
}
COMPLEX mult(COMPLEX c1,COMPLEX c2)
{
  COMPLEX c4;
  c4.real=(c1.real*c2.real)-(c1.imag*c2.imag);//real part
  c4.imag=(c1.real*c2.imag)+(c1.imag*c2.real);//imaginary part
  return c4;
}
int main(void) {
  COMPLEX c1,c2,c3,c4;
  printf("Enter two complex numberslike(real,imaginary)\n");
  scanf("%lf,%lf",&c1.real,&c1.imag);
  scanf("%lf,%lf",&c2.real,&c2.imag);
  c3=add(c1,c2);
  printf("On addition we get %0.02lf +i(%0.02lf)\n",c3.real,c3.imag);
  c4=mult(c1,c2);
  printf("On multiplication we get %0.02lf +i(%0.02lf)",c4.real,c4.imag);
  return 0;
}