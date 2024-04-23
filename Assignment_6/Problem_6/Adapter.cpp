#include <iostream>
using namespace std;
class Shape
{ // abstract class
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
  Triangle(double x,double y, double z,double w)
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
class Figure : public Shape
{
  public:
  double area()
  {
    return this->area(); // prints the area of the current object
  }
  double perimeter()
  {
   return this->perimeter();//prints the perimeter of the current object
  }
};
class RectangularFigure : public Figure, public Rectangle
{  
  Rectangle* r;
  public:
  RectangularFigure() : Rectangle()
  {
    r=new Rectangle(2,3);
  }
  double area()
  {
    return (r->area());
  }
  double perimeter()
  {
    return (r->perimeter());
  }
};
class CircularFigure : public Figure, public Circle
{
  Circle* c;
  public:
  CircularFigure() : Circle()
  {
    c=new Circle(1);
  }
  double area()
  {
    return (c->area());
  }
  double perimeter()
  {
    return (c->perimeter());
  }
};
void printArea(Figure* f) { // prints the area
cout<<"Area = "<<f->area()<<endl;
}
int main() {
Figure* f1 = new RectangularFigure();
Figure* f2 = new CircularFigure();
printArea(f1);
printArea(f2);
}