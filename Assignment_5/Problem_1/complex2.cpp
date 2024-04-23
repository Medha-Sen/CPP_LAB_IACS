#include <iostream>
using namespace std;
class Complex
{
  int r,im;
  public:
  Complex(int real=0,int imag=0) //parameterized constructor
  {
    r=real;
    im=imag;
  }
  Complex& operator+(const Complex& c) // add operation overloading
  {
    static Complex a;
    a.r=this->r+c.r;
    a.im=this->im+c.im;
    return a;
  }
  Complex& operator-(const Complex& c) //subtract operation overloading
  {
    static Complex a;
    a.r=this->r-c.r;
    a.im=this->im-c.im;
    return a;
  }
  Complex& operator*(const Complex& c) //multiply operator overloading 
  {
    static Complex a;
    a.r=(this->r*c.r)-(this->im*c.im);
    a.im=(this->im+c.r)+(this->r*c.im);
    return a;
  }
  int get_real() const // returns real part
  {
    return this->r;
  }
  int get_imaginary() const // returns imaginary part
  {
    return this->im;
  }
};
bool operator>(const Complex& c1, const Complex& c2)
{ // overloading the comparison operator
  if(c1.get_imaginary()==0 && c2.get_imaginary()==0)
  {
    if(c1.get_real()>c2.get_real())
      return true;
  }
  return false;
}
int main() 
{
  Complex c1(1,2);
  Complex c2(3,4);
  Complex& c_add=c1+c2;
  cout<<"Addition value is "<<c_add.get_real()<<"+"<<c_add.get_imaginary()<<"i"<<endl;
  Complex c_sub=c1-c2;
    cout<<"Subtraction value is "<<c_sub.get_real()<<"+"
      <<c_sub.get_imaginary()<<"i"<<endl;
  Complex c_mul=c1*c2;
    cout<<"Multiplication value is "<<c_mul.get_real()<<"+"<<c_mul.get_imaginary()<<"i"<<endl;
  if(c1>c2)
    cout<<"C1 has a greater real value"<<endl;
  else
    cout<<"C2 has a greater real value"<<endl;
}