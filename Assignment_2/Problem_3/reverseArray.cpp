#include <iostream>
using namespace std;
void copy_arr(int arr1[],int arr2[],int n)
{
  for(int i=n-1;i>=0;i--)
  {
    arr2[n-i-1]=arr1[i];// reversing the elements of the array index wise 
  }
}
int main() {
  int n;
  int *arr1, *arr2;
  cout << "Enter the size of the array\n";
  cin>>n;
  arr1=(int*)malloc(sizeof(int)*n);
  arr2=(int*)malloc(sizeof(int)*n);
  cout << "Enter the array elements\n";
  for(int i=0;i<n;i++)
  {
    cin>>arr1[i];
  }
  copy_arr(arr1,arr2,n);
  cout << "Displaying the reverse array\n";
   for(int i=0;i<n;i++)
  {
    cout<<arr2[i]<<endl;
  }
}