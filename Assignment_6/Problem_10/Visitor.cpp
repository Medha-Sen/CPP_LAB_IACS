#include <iostream>
using namespace std;
struct student
{
  int roll;
  string name;
  double agg;
};
bool operator > (student x,student y) 
{// overloading > operator based on student records
   if (x.agg > y.agg)
     return true;
  else
    return false;
};
template<typename T>
void selection_sort(T arr[],int n)
{
   int i, j, minx;
    T temp;
   for (i = 0; i < n-1; i++)
   {
      minx = i;
      for (j = i+1; j < n; j++)
      if (arr[minx]>arr[j])
          minx = j;
      if(minx!=i)
      { 
         temp=arr[i];
         arr[i]=arr[minx];
         arr[minx]=temp;
      }        
   }
}
template<typename T>
void print(T arr[],int n)
{
  for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<endl;
    }
  cout<<"*************************"<<endl;
}
void print(student s[],int n)
{
  for(int i=0;i<n;i++)
    {
      cout <<"name: "<< s[i].name ;
      cout <<", roll: "<<s[i].roll;
      cout <<", aggregate: "<<s[i].agg<<endl;
    }
}
int main() {
  int arr1[5]={6,3,4,1,2};
  selection_sort<int>(arr1,5);
  print(arr1,5);
  char arr2[5]={'z','d','a','c','l'};
  selection_sort<char>(arr2,5);
  print(arr2,5);
  string arr3[5]={"teacher","doctor","artist","actor","pianist"};
  selection_sort<string>(arr3,5);
  print(arr3,5);
  student arr4[5];
  for(int i=0;i<5;i++)
    {
      cout<<"Enter the student name"<<endl;
      cin>>arr4[i].name;
      cout<<"Enter the roll no."<<endl;
      cin>>arr4[i].roll;
      cout<<"Enter the aggregate marks"<<endl;
      cin>>arr4[i].agg;
    }
  selection_sort<student>(arr4,5);
  print(arr4,5);
}