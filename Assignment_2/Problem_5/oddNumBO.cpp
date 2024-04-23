#include <iostream>
using namespace std;
int find_odd(int arr[],int n) // method to find the only element occurring odd number of times
{
  int res = 0;
  for (int i = 0; i < n; i++) {
      res = (res ^ arr[i]); //Bitwise XOR of all the elements
   }
return res;
}
int main() {
 int n;
  int *arr;
  cout << "Enter the size of the array\n";
  cin>>n;
  arr=(int*)malloc(sizeof(int)*n);
  cout << "Enter the array elements\n";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout<<"Element occuring odd times is "<<find_odd(arr,n);
}