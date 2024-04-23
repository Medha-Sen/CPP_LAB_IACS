#include <stdio.h>
int main(void) {
  int a=1,b=2,c=3,d=4,res=0;
  res=a+b-c+d;//1+2-3+4= 4
  printf("res=%d\n",res);// prints 4
  res=a*b/c;//1*2/3= 2/3= 0
  printf("res=%d\n",res);// print 0
  res=1+a*b%c;//1+1*2%3= 1+2%3=3
  printf("res=%d\n",res);// prints 3
  res=a+d%b-c;//1+4%2-3= 1+0-3= -2
  printf("res=%d\n",res);//prints -2
  res=b=d+c/b-a;//4+3/2-1= 4+1-1= 4
  printf("res=%d\n",res);//prints 4
  return 0;
}