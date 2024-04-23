#include<iostream>
using namespace std;
char *reverse(char *s,int n) // reverses the string
{
	char temp;
	int l=n-1;
	for(int i=0;i<=(l/2);i++)
	{
	  temp=s[i];
	  s[i]=s[l];
	  s[l]=temp;
	  l--;
	}
	return s;	
}
void check_palin(char *s,int n) // checks whether string is palindrome
{
	char *st=new char[n];
	int i,flag=0;
	for( i=0;s[i]!='\0';i++)
	{
		st[i]=s[i];
	}
	st[i]='\0';
	reverse(st,n);
	for(i=0;s[i]!='\0';i++)
	{
		if(st[i]!=s[i])
			flag=1;
	}
	if (flag)
    cout<<"Not Palindrome. The reverse string is "<<st<<endl;
  else
    cout<<"The string is Palindrome"<<endl;
}
int main()
{
	int n;
	cout<<"Enter the size of the string"<<endl;
	cin>>n;
	char *s=new char[n];
	cout<<"Enter the word"<<endl;
	cin>>s;
	check_palin(s,n);
	return 0;
}
