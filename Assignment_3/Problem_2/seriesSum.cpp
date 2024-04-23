#include <iostream>
using namespace std;
inline int square(int x){return x*x;} // inline function
int main() {
  int n,i,sum=0;
  cout << "Enter the value of n\n";
  cin>>n;
  for(i=1;i<=n;i++)
  {
    sum+=square(i);
  }
  cout<<"The sum computed is "<<sum<<endl;
}