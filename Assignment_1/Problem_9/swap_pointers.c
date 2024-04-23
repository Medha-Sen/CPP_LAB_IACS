#include <stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{// method to swap integers using pointers
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int main(void) {
  int a,b;
  printf("Enter 2 integers\n");
  scanf("%d,%d",&a,&b);
  printf("Initially, a=%d and at address=%p\n",a,&a);
  printf("Initially, b=%d and at address=%p\n",b,&b);
  swap(&a,&b);
   printf("Finally, a=%d and at address=%p\n",a,&a);
  printf("Finally, b=%d and at address=%p\n",b,&b);
  return 0;
}