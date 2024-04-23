#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *s1,char *s2)
{ // method to swap two strings
 char *temp=(char *)malloc((strlen(s1) + 1) * sizeof(char));
 strcpy(temp, s1);
 strcpy(s1, s2);
 strcpy(s2, temp);
}
void reverse(char *s) //method to reverse a string
{ char temp; 
  int len=strlen(s)-1;
  for(int i=0;i<len;i++)
    {
       temp = s[i];  
       s[i] = s[len];  
       s[len] = temp;  
       len--;
    }
}
void amend(char str[])
{ //method to remove any character from the string other than digits and the string termination character
  int i,j;
  for(i = 0; str[i] != '\0'; ++i)
  { while (!( (str[i] >= '0' && str[i] <= '9')|| str[i] == '\0'))
   { for(j = i; str[j] != '\0'; ++j)
      {str[j] = str[j+1];}
     str[j] = '\0';
    }
  }
}
char *add(char str1[], char str2[]) 
{ //method to add two large numbers
  char c;
  int sum=0,carry = 0; 
  if (strlen(str1) > strlen(str2)) 
   swap(str1, str2); //fixing the variables as per string length 
  char *s3;
  s3=(char*)malloc(sizeof(char)*100);
  amend(str1);amend(str2);//Precaution of non digit chars  
  reverse(str1); reverse(str2); //reversing both number strings
  int n1 = strlen(str1), n2 = strlen(str2); 
  for (int i=0; i<n1; i++) 
  { 
    sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
    c=(sum%10) + '0';
    strncat(s3,&c,1); 
    carry = sum/10; 
  } 
  // Adding the remaining digits of the larger number 
  for (int i=n1; i<n2; i++) 
  { 
    sum = ((str2[i]-'0')+carry); 
    c=(sum%10) + '0';
    strncat(s3,&c,1);
    carry = sum/10; 
  } 
  // Adding the remaining carry (if any)
  if (carry) 
  { c=carry + '0';
    strncat(s3,&c,1);}   
  reverse(s3); // reverse resultant string 
  amend(s3);
  return s3; 
} 

void multiply(char s1[],char s2[])
{
  int sum=0,temp=0,i,j,x,k=0;
  char c;
  char *s3,*s4;
  s4=(char*)malloc(sizeof(char)*100);
  reverse(s1);reverse(s2);
  if(strlen(s2)>strlen(s1))
   swap(s1,s2);//fixing the variables as per string length 
  for(i=1;i<strlen(s2);i++)
  { 
    s3=(char*)malloc(sizeof(char)*100);
    temp=0;// stores the carry
    for(j=1;j<strlen(s1);j++)
      {
        sum=(s1[j]-'0')*(s2[i]-'0')+temp;
        c=(sum%10 + '0');
        strncat(s3, &c, 1);
        temp=sum/10;        
      }
    if (temp)//if we have a non-zero carry
    {  c=temp + '0';
       strncat(s3,&c,1);
    }
    amend(s3);
    reverse(s3);
    for(x=0;x<k;x++)
    { //shifting ith line by (i-1)th space
      c='0';
      strncat(s3, &c, 1);  
    }
    reverse(s3);
    if(k==0) // Case of first line of multipication
    {
      strcpy(s4,s3);// s4 stores the result string
      free(s3);
      k++;
    }
    else
    { // Case of other lines of multiplication
      reverse(s4);reverse(s3);
      strcpy(s4,add(s4,s3));
      free(s3);
      reverse(s4);
      k++;
    }   
  }
  reverse(s4);
  printf("%s\n",s4); 
}
int main(void) {
 char s1[100],s2[100];
  char *s5;
  s5=(char*)malloc(sizeof(char)*100);
  printf("Enter two large numbers\n");
  fgets(s1,1000,stdin);
  fgets(s2,1000,stdin);
  printf("Product : \n");
  multiply(s1,s2);
  printf("Sum : \n");
  reverse(s1);reverse(s2);
  s5=add(s1,s2); 
  printf("%s\n",s5);
  return 0;
}