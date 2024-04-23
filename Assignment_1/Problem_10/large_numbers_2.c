#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *s1,char *s2)
{ //method to swap strings
 char temp=*s1;
  *s1=*s2;
  *s2=temp;
}
void print_string(char s[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c",s[i]);
    printf("\n");
}
void Permutation(char s[], int size, int n)
{ // Heap's Algorithm
    if (size == 1) {//if size==1 prints obtained permutation
        print_string(s, n);
        return;
    }
    for (int i = 0; i < size; i++) {
        Permutation(s, size - 1, n);
        if (size % 2 == 1)//if size is odd, swap 0th and (size-1)th element
            swap(&s[0], &s[size - 1]);
        else //if size is even, swap ith and (size-1)th element
            swap(&s[i], &s[size - 1]);
    }
} 
int main(void) {
  char *s;
  s=(char*)malloc(sizeof(char)*1000);
  printf("Enter the number\n");
  fgets(s,1000,stdin);
  printf("Permutations are\n");
 Permutation(s,strlen(s)-1,strlen(s)-1);
  return 0;
}