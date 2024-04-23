#include <iostream>
using namespace std;
int factorial(int n)
{
    return ((n == 1 || n == 0)?1:n*factorial(n-1));   // Recursive method to calculate the factorial
} 
int main() {
  int n,f;
  cout << "Enter an integer\n";
  cin>>n;
  if (n>=0)
  {
    f=factorial(n);
    cout<<f<<endl;
  }
  else
    cout<<"Enter a positive integer";  
}