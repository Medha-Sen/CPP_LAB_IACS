#include<iostream>
using namespace std;
class Complex
{
  double real,imag;
  public:	
  Complex(double r=0.0,double i=0.0);
  void real_set(double r); // sets the real part
  void imaginary_set(double i); //sets the imaginary part
  double real_get() const;  //returns real part
  double imaginary_get() const; // returns imaginary part
  void display() const;
  Complex add(Complex & c) const;
  Complex sub(Complex & c) const;
  Complex mul(Complex & c) const;
  Complex div(Complex & c) const;
};
  Complex::Complex(double r,double i)
  {
    real_set(r);
    imaginary_set(i);
  }
  void Complex::real_set(double r){real=r;}
  void Complex::imaginary_set(double i){imag=i;}
  double Complex::real_get() const {return real;}
  double Complex::imaginary_get() const {return imag;}
  void Complex::display() const // displays the number
	{
		if(imag==0)
			cout<<"The complex number is: "<< real<<endl;
		else
		{
			if(imag>0)
			{
				if(imag==1.0)
					cout<<"The complex number is: "<< real<<"+i"<<endl;
				else
					cout<<"The complex number is: "<< real<<"+i"<<imag<<endl;
			}
			else
			{
				if(imag==-1.0)
					cout<<"The complex number is: "<< real<<"-i"<<endl;
				else
					cout<<"The complex number is: "<< real<<"-i"<<imag<<endl;
			}
		}
    }
    Complex Complex::add(Complex & c) const //addition 
    {
    	Complex c3;
    	c3.real=real_get()+c.real_get();
    	c3.imag=imaginary_get()+c.imaginary_get();
    	return c3;
    }
Complex Complex::sub(Complex & c) const //subtraction
    {
    	Complex c3;
    	c3.real=real_get()-c.real_get();
    	c3.imag=imaginary_get()-c.imaginary_get();
    	return c3;
    }
    Complex Complex:: mul(Complex & c) const //multiplication
    {
     	Complex c3;
     	c3.real=(real_get()*c.real_get())-(imaginary_get()*c.imaginary_get());
     	c3.imag=(real_get()*c.imaginary_get())+(imaginary_get()*c.real_get());
     	return c3;
    }
    Complex Complex:: div(Complex & c) const //division
    {
		Complex c3;
	 	c3.real=((real_get()*c.real_get())+(imaginary_get()*c.imaginary_get()))/((c.real_get()*c.real_get())+(c.imaginary_get()*c.imaginary_get()));
	 	c3.imag=((c.real_get()*imaginary_get())-(c.imaginary_get()*real_get()))/((c.real_get()*c.real_get())+(imaginary_get()*c.imaginary_get()));
	 	return c3;
    }	
int main()
{
	double r1,r2,i1,i2;
	int c;
	Complex c3;
	cout<<"Enter the first complex number (real followed by imaginary)"<<endl;
	cin>>r1;
  cin>>i1;
	Complex c1(r1,i1);
	cout<<"Enter the second complex number (real followed by imaginary)"<<endl;
	cin>>r2;
  cin>>i2;
	Complex c2(r2,i2);
	cout<<"Enter 1 to add, 2 to subtract, 3 to multiply and 4 to divide the complex numbers"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>c;
	switch(c) // switch case to select an operation choice
	{
		case 1: c3=c1.add(c2);
		c3.display();
			break;
		case 2: c3=c1.sub(c2);
		c3.display();
			break;
		case 3: c3=c1.mul(c2);
		c3.display();
			break;
		case 4: if(i2!=0 && r2!=0)
        {
				c3=c1.div(c2);
				c3.display();
				break;
			  }
			  else
			  	cout<<"Division by zero is not allowed"<<endl;
			  break;
		default:cout<<"Invalid choice!";
	}	
}