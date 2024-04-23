#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//Using the Knuth Morris Pratt algorithm
//lps is Longest Prefix Suffix
void lps_table(char* s2, int M, int* lps)
{
    int len = 0; 
    lps[0] = 0; // lps[0]=0 
    // calculating lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) 
    {
      if (s2[i] == s2[len]) {
        len++;
        lps[i] = len;
        i++;
      }
      else //(pat[i] != pat[len])
      {
        if (len != 0) 
        {len = lps[len - 1];
        }
        else // if (len == 0)
        {
          lps[i] = 0;
          i++;
        }
      }
    }
}
int mySubStr(char s1[],char s2[])
{
    int M = strlen(s2);
    int N = strlen(s1); 
    int lps[M];
    lps_table(s2, M, lps); 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) { //string check in KMP Algo
        if (s2[j] == s1[i]) {
            j++;
            i++;
        } 
        if (j == M) {
            return i-j;
            j = lps[j - 1];
        }
        else if (i < N && s2[j] != s1[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
  return -1;
}
int main(void) {
  char s1[400],s2[400]; 
  int p=-1;
  printf("Enter the search string\n");
  scanf("%s",s1);
  printf("Enter the pattern to search for in the string\n");
  scanf("%s",s2);
  p=mySubStr(s1,s2);
  if(p==-1)
    printf("Pattern not found in string\n");
  else
    printf("Pattern found in position %d\n",p);
  return 0;
}