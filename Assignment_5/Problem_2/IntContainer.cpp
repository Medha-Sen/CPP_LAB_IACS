#include <iostream>
using namespace std;
class IntContainer
{
  int n;
  int *arr;
  public:
  IntContainer(int len=0) // parameterized constructor
  {
    n=len;
    arr=new int[len];
    for(int i=0;i<len;i++)
      {
        cout<<"Enter a value"<<endl;
        cin>>arr[i];
      }
  }
  int get_length() // returns size of the array
  {
    return this->n;
  }
  IntContainer& operator+=(int a) // += operator overloading
  {   
    for(int i=0;i<n;i++)
      {
        arr[i]+=a;
      }
    return *this;
  }
  IntContainer& operator-=(int a) // -= operator overloading
  {
    for(int i=0;i<n;i++)
      {
        arr[i]-=a;
      }
    return *this;
  }
  IntContainer& operator++()// prefix increment overload
  {    
    for(int i=0;i<n;i++)
      {
        ++arr[i];
      }
    return *this;
  }
IntContainer& operator++(int) // postfix increment overload
  {
    static IntContainer ic1;
    ic1.n=get_length();
    for(int i=0;i<n;i++)
      {
        ic1.arr[i]=arr[i];
        arr[i]++;
      }
    return ic1;
  }
 IntContainer& operator--() // prefix decrement overload
  {
    for(int i=0;i<n;i++)
      {
        --arr[i];
      }
    return *this;
  }
  IntContainer& operator--(int) // postfix decrement overload
  {
    static IntContainer ic2;
    ic2.n=get_length();
    for(int i=0;i<n;i++)
      {
        ic2.arr[i]=arr[i];
        arr[i]--;
      }
    return ic2;
  }
  void print() //prints the array
  {
    for(int i=0;i<this->n;i++)
      {
        cout<<this->arr[i]<<endl;
      }
  }
};
int main() {
  int n=5;
  IntContainer ic(3);
  ic+=2;
  cout<<"Increased every value by 2"<<endl;
  ic.print();
  ic-=2;
  cout<<"Decreased every value by 2"<<endl;
  ic.print();
  IntContainer icc1=++ic;
  cout<<"Increased every value by 1(prefix)"<<endl;
  icc1.print();
  IntContainer icc2=--ic;
  cout<<"Decreased every value by 1(prefix)"<<endl;
  icc2.print();
  IntContainer icc3=ic++;
  cout<<"Increased every value by 1(postfix)"<<endl;
  icc3.print();
  IntContainer icc4=ic--;
  cout<<"Decreased every value by 1(postfix)"<<endl;
  icc4.print();
}