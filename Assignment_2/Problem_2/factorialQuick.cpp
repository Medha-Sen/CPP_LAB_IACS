#include <iostream>
using namespace std;
int factorial(int n)
{
  switch(n)
 { // hard coding the values to be returned
   case 0: cout<<"The factorial is \n";return 1;
   case 1: cout<<"The factorial is \n";return 1;
   case 2: cout<<"The factorial is \n";return 2;
   case 3: cout<<"The factorial is \n";return 6;
   case 4: cout<<"The factorial is \n";return 24;
   case 5: cout<<"The factorial is \n";return 120;
   case 6: cout<<"The factorial is \n";return 720;
   case 7: cout<<"The factorial is \n";return 5040;
   case 8: cout<<"The factorial is \n";return 40320;
   case 9: cout<<"The factorial is \n";return 362880;
   case 10: cout<<"The factorial is \n";return 3628800;
   case 11: cout<<"The factorial is \n";return 39916800;
   case 12: cout<<"The factorial is \n";return 479001600;
   default: cout<<"Enter a lower input"<<endl;return 0; // returns 0 otherwise
 } 
}
int main() {
int n,sum=0;
  cout << "Enter an integer\n";
  cin>>n;
  if (n>=0)
  {
    sum=factorial(n);
    if(sum)
    cout<<sum<<endl;
  }
  else
    cout<<"Enter a positive integer"; 
}