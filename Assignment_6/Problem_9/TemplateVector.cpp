#include <iostream>
using namespace std;
class Negative_Size : public std:: exception
{
  public:
  void message()
  {
    cout<<"Negative Size not allowed!"<<endl;
  }
};
template <class T> 
class Vector
{
  private:
  T* elem;
  int sz;
  public:
  Vector(int s=0)
  {
    if (s<0) throw Negative_Size();
    elem = new T[s];
    sz = s;
    for(int i=0;i<sz;i++)
    {
      cout<<"Enter the element\n";
      cin>>elem[i];
    }
  }
  T& operator[](int i)
  {
    return elem[i];
  }
  const T& operator[](int i) const
  {
    return elem[i];
  }
  int getSize() const
  {
     return sz;
  }
  void print() 
  {
    cout<<"Printing array elements:"<<endl;
    for(int i=0;i<sz;i++)
      {
        cout<<elem[i]<<endl;
      }
  }
};
int main() {
  try{
  int n;
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
  Vector<int> v1(n);
  v1.print();    
  cout<<"Size of the array is: "<<v1.getSize()<<endl;
  }
  catch(Negative_Size n)
  {
    n.message();
  }
  }