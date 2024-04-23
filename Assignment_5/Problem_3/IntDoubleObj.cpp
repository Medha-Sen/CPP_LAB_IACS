#include <iostream>
using namespace std;
class IntObject
{
  int i;
  public:
  IntObject(int x=0) // paramterized constructor
  {
    this->i=x;
  }
  operator int() // overloads int type
  {
    return i;
  }
};
class DoubleObject
{
  double j;
  public:
  DoubleObject(double x=0.0) // paramterized constructor
  {
    this->j=x;
  }
  operator double() // overloads double type
  {
    return j;
  }
  operator IntObject() // overloads IntObject type
  {
    return (int)j;
  }
};
int main() {
  IntObject i(6);
  int x= i;
  cout<<"x has a value "<<x<<endl;
  DoubleObject j(2.3);
  double y= j;
  cout<<"y has a value "<<y<<endl;
  DoubleObject k(2.6);
  IntObject z=k;
  cout<<"z has a value "<<z<<endl; 
}