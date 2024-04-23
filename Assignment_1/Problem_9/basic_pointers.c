#include <stdio.h>
int main(void) {
  int x,y;
  int *ptr;
  x=10;
  ptr=&x;// value of x is assigned to the pointer ptr
  y=*ptr;// variable y stores the content of the address pointed to by the pointer ptr
  printf("%d is stored in location %p \n",x,&x);
  // displays the value and address of variable x
  printf("%d is stored in location %p \n",*&x,&x);
  // the first part displays the content and address of the variable x by deferencing it 
  printf("%d is stored in location %p \n",*ptr,ptr);
  //displays variable x's content and address via its pointer
  printf("%d is stored in location %p \n",y,&*ptr);
  // displays y's content and the address pointed to by the pointer ptr
  printf("%p is stored in location %p \n",ptr,&ptr);
  // displays the address pointed to by pointer ptr and the address of the ptr itself
  printf("%d is stored in location %p \n",y,&y);
  //displays the value and address of integer variable y
  *ptr=25;// The content of the address pointed to by the pointer (i.e x) changes to 25.
  printf("\nNow x= %d \n",x);// prints x as 25
  return 0;
}