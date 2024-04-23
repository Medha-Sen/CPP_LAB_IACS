#include <iostream>
using namespace std;
class Overflow : public std::exception{ //user defined exception
public:
 void message()
{
  cout<<"Stack Overflow!"<<endl;
}
};
class Underflow : public std::exception{ //user defined exception
public:
 void message()
{
  cout<<"Stack Underflow!"<<endl;
}
};
class Stack
{
  int n;
  int top;
  int *arr;
  public:
  Stack(int size)
  {
    n=size;
    top=-1;
    arr=new int[n];
  }
  void push() // pushes an elemnt in the stack
  {
    if(top<n-1)
    {
      cout<<"Enter a value"<<endl;
      cin>>arr[++top];
    }         
    else
      throw Overflow(); //throws an exception

  }
  void pop() // pops an element out of the stack
  {
    if(top>-1)
    {
      cout<<"Popping: "<<arr[top]<<endl;
      --top;
    }
    else
      throw Underflow(); // throws an exception
  }
  void print() // prints the stack content
  {
    cout<<"The stack content is as follows:"<<endl;
    for(int i=top;i>=0;i--)
      {
        cout<<arr[i]<<endl;
      }
  }
};
int main() {
  int n;
  cout<<"Enter stack size"<<endl;
  cin>>n;
  Stack s(n);
  try{
  s.push();s.push();
  }
  catch(Overflow o)
  {
    o.message();
  }  
  try{
  s.pop();s.pop();s.pop();s.print();}
  catch(Underflow u)
  {
    u.message();
  }  
}