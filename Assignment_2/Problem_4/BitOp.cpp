#include <iostream>
using namespace std;
int count_one(int n) // method to count the number of 1s
{
  if(n==0)
    return 0;
  else
    return ((n&1) + count_one(n>>1));
}
int trail_zero(int n)// method to count the number of trailing zeroes
{
  if((n & 1)==1)
   return 0;
  else
    return (1+trail_zero(n>>1));
    
}
int reverse(int n) // method to reverse the bits of a number
{
  int rev=0;
  while(n>0)
  {
    rev<<=1;
    if((n & 1)==1)
      rev^=1;
    n>>=1;
  }
  return rev;
}
int main() {
  int a,b;
  cout<<"Enter two numbers a and b"<<endl;
  cin>>a>>b;
  cout<<"Multiplication of a with 8"<<endl;
  cout << (a<<3)<<endl;
  cout<<"Number of 1s in a is"<<endl;
  cout<<count_one(a)<<endl;
  cout<<"Number of trailing 0s in a is"<<endl;
  cout<<trail_zero(a)<<endl;
  cout<<"Reversing the number"<<endl;
  cout<<reverse(a)<<endl;
  cout<<"BITWISE OR"<<endl;
  cout<<(a | b)<<endl;
  cout<<"BITWISE AND"<<endl;
  cout<<(a & b)<<endl;
  cout<<"BITWISE XOR"<<endl;
  cout<<(a ^ b)<<endl;
}