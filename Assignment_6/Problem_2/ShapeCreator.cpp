#include <iostream>
#include <string>
using namespace std;
class Shape
{ //abstract class
  public:
  virtual double area()=0;
  virtual double perimeter()=0;
};
class Rectangle : public Shape
{
  double l,b;
  public:
  Rectangle(double x=0.0,double y=0.0)
  {
    l=x;
    b=y;
  }
  double area()
  {
    return (l*b);
  }
  double perimeter()
  {
    return (2*l+2*b);
  }
};
class Circle : public Shape
{
  double r;
  public:
  Circle(double x=0.0)
  {
    r=x;
  }
  double area()
  {
    return (3.14*r*r);
  }
  double perimeter()
  {
    return (2*3.14*r);
  }
};
class Triangle : public Shape
{
  double b,h,s1,s2;
  public:
  Triangle(double x=0.0,double y=0.0, double z=0.0,double w=0.0)
  {
    b=x;
    h=y;
    s1=z;
    s2=w;
  }
  double area()
  {
    return (0.5*b*h);
  }
  double perimeter()
  {
    return (b+s1+s2);
  }
};
void compute(Shape* s)
{
  if(s!=nullptr)
  {
    cout<<"The area is "<<s->area()<<endl;
    cout<<"The perimeter is "<<s->perimeter()<<endl;
  }
}
class ShapeNotSupported : public std::exception{ //exception class
  public:
  void message()
  {
    cout<< "Not a supported shape"<<endl;
  }
};
class ShapeCreator 
{
  public:
  Shape* create(string s) 
  {
    int a;
    if(s=="Rectangle" || s=="rectangle")
    { 
      return new Rectangle(2,3);
    }
    else if (s=="Circle" || s=="circle")
    { 
     return new Circle(1);
    }
    else if(s=="Triangle" || s=="triangle")
    { 
      return new Triangle(4,2,3,5);
    }
    else
      throw ShapeNotSupported();
  }
};
void task()
{
  string name;
  ShapeCreator sc;
  Shape* p;
  cout<<"Enter a shape name (Rectangle/Circle/Triangle)"<<endl;
  cin>>name;
  try
    {
      p=sc.create(name);
    }
  catch(ShapeNotSupported e)
      {
        e.message();
        exit(1);
      }
  compute(p);
}
int main() {
  task();
}