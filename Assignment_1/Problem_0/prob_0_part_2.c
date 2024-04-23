#include <stdio.h>
int main(void) {
 int ans,val=4;
  val=val+1;// val=4+1= 5
  printf("ans=%d val=%d\n",ans,val);// ans prints a garbage value as it was never initialized with a value
  val++;// postfix operator (5++)
  ++val;//(++6)=7
  printf("ans=%d val=%d\n",ans,val);// ansis printed as 0 by the compiler and val =7
  ans=2*val++;// 2*7=14, val becomes 8 after the operation because of the postfix increment operator
  printf("ans=%d val=%d\n",ans,val);// prints 14 and 8
  val--;//(8--)
  --val;//(--7)=6
  printf("ans=%d val=%d\n",ans,val);//prints 14 and 6
  ans=--val*2;//5*2= 10
  printf("ans=%d val=%d\n",ans,val);//prints 10 and 5
  ans=val--/3;// 5/3=1, val becomes 4 after the operation
  printf("ans=%d val=%d\n",ans,val);//1 and 4
  return 0;
}