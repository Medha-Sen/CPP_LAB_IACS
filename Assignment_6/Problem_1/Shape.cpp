#include <iostream>
using namespace std;
class Shape // abstract class
{
  public:
  virtual double area() const =0; //pure virtual function
  virtual double perimeter() const =0; // pure virtual function
};
class Rectangle : public Shape
{
  double l,b;
  public:
  Rectangle(double x,double y) // parameterized constructor
  {
    l=x;
    b=y;
  }
  double area() const // returns area
  {
    return (l*b);
  }
  double perimeter() const //returns perimeter
  {
    return (2*l+2*b);
  }
};
class Circle : public Shape
{
  double r;
  public:
  Circle(double x)
  {
    r=x;
  }
  double area() const //returns area
  {
    return (3.14*r*r);
  }
  double perimeter() const //returns perimeter
  {
    return (2*3.14*r);
  }
};
class Triangle : public Shape
{
  double b,h,s1,s2;
  public:
  Triangle(double x,double y, double z,double w)
  {
    b=x;
    h=y;
    s1=z;
    s2=w;
  }
  double area() const // returns area
  {
    return (0.5*b*h);
  }
  double perimeter() const //returns perimeter
  {
    return (b+s1+s2);
  }
};
void compute(const Shape* s) // method to display area & perimeter
{
  cout<<"The area is "<<s->area()<<endl;
  cout<<"The perimeter is "<<s->perimeter()<<endl;
}
int main() {
  Rectangle R(2,3);
  Circle C(1);
  Triangle T(4,2,3,5);
  Shape* s=&R;
  compute(s); 
}