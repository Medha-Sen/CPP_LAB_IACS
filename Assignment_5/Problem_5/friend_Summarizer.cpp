#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class IntContainer
{
  int n;
  int *arr;
  public:
  friend void Summarizer(const IntContainer&); //friend
  IntContainer(int len=0) //parameterized constructor
  {
    n=len;
    arr=new int[len];
    for(int i=0;i<len;i++)
      {
        cout<<"Enter a value"<<endl;
        cin>>arr[i];
      }
  }
  int get_length() // returns array length
  {
    return this->n;
  }
  IntContainer& operator+=(int a) //operator overloading
  {   
    for(int i=0;i<n;i++)
      {
        arr[i]+=a;
      }
    return *this;
  }
  IntContainer& operator-=(int a)//operator overloading
  {
    for(int i=0;i<n;i++)
      {
        arr[i]-=a;
      }
    return *this;
  }
  IntContainer& operator++() //operator overloading
  {  
    for(int i=0;i<n;i++)
      {
        ++arr[i];
      }
    return *this;
  }
  IntContainer& operator++(int) //operator overloading
  {
    static IntContainer icc1;
    icc1.n=get_length();
    for(int i=0;i<n;i++)
      {
        icc1.arr[i]=arr[i];
        arr[i]++;
      }
    return icc1;
  }
 IntContainer& operator--() //operator overloading
  {
    for(int i=0;i<n;i++)
      {
        --arr[i];
      }
    return *this;
  }
  IntContainer& operator--(int) //operator overloading
  {
    static IntContainer icc2;
    icc2.n=get_length();
    for(int i=0;i<n;i++)
      {
        icc2.arr[i]=arr[i];
        arr[i]--;
      }
    return icc2;
  }
  void print() //prints the array
  {
    for(int i=0;i<this->n;i++)
      {
        cout<<this->arr[i]<<endl;
      }
  }
};
void Summarizer(const IntContainer& ic)
{
  double mean=0;
  int median,mode;
  for(int i=0;i<ic.n;i++)
    {
      mean+=ic.arr[i];
    }
  cout<<"Mean is :"<<mean/ic.n<<endl;
  sort(ic.arr, ic.arr + ic.n);
  if(ic.n % 2 == 0)
    median=(ic.arr[ic.n/2 - 1] + ic.arr[ic.n/2])/2;
  else
   median=ic.arr[ic.n/2];
  cout<<"Median is :"<<median<<endl;
  int max_count = 1, res = ic.arr[0], count = 1; 
    for (int i = 1; i < ic.n; i++) { 
        if (ic.arr[i] == ic.arr[i - 1]) 
            count++; 
        else { 
            if (count > max_count) { 
                max_count = count; 
                res = ic.arr[i - 1]; 
            } 
            count = 1; 
        } 
    } 
  
    // when the last element is most frequent 
    if (count > max_count) 
    { 
        max_count = count; 
        res = ic.arr[ic.n - 1]; 
    } 
    
    mode= res;
   cout<<"Mode is :"<<mode<<endl;
  
}
int main() {
  int n;
  cout<<"Enter array size"<<endl;
  cin>>n;
  IntContainer ic(n);
  Summarizer(ic);
}