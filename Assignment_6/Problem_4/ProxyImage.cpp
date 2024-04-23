#include <iostream>
#include<iomanip>
using namespace std;
class Image
{ //abstract class
  public:
  virtual int get_height()=0; //pure virtual function
  virtual int get_width()=0;
};
class RealImage : public Image
{
  string name;
  int h,w;
  int *arr; 
  public:
  RealImage(int x=0.0,int y=0.0,string n="")
  {
    name=n;
    h=x;w=y;
    arr=new int[h*w];
    int v;
    for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
      {
        cout<<"Enter a value in the matrix in the range(0-255)\n";
        cin>>v;
        setValue(v,i,j);
      }
    }
  }
  string get_name() // returns image file name
  {
   return name;
  }
  int get_height() // returns image height
  {
   return h;
  }
  int get_width() // returns image width
  {
    return w;
  }
  int& get(int r, int c) const // returns matrix element
  {
    return arr[w * r + c];
  }
  void setValue(int v, int r, int c) // sets element value
  {
   get(r, c) = v;
  }
  int getValue(int r, int c) const //returns value
  {
   return get(r, c);
  }
  void get_matrix() // prints the matrix
  {
    std::cout << std::fixed << std::setprecision(1);
    for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
    std::cout << (c > 0 ? " " : "") << std::setw(4);
    std::cout << getValue(r, c);
    }
    std::cout << std::endl;
    }
  }  
};
class ProxyImage : public Image
{
  string name;
  int h,w;
  RealImage* p;
  public:
  ProxyImage(RealImage r)
  {
    h=r.get_height();
    w=r.get_width();
    name=r.get_name();
    p=&r;
  }
  string get_name() // returns file name
  {
   return name;
  }
  int get_height() // returns image height
  {
   return h;
  }
  int get_width() // returns image width
  {
    return w;
  }
  void get_matrix() // request delegation to RealImage
  {
   p->get_matrix();
  }
};
int main() {
  string n;
  cout<<"Enter Image file name\n";
  cin>>n;
  RealImage r(2,2,n);
  ProxyImage p(r);
  cout<<"Image file name:"<<endl;
  cout<<p.get_name()<<endl;
  cout<<"The height of Image:"<<endl;
  cout<<p.get_height()<<endl;
  cout<<"The width of Image:"<<endl;
  cout<<p.get_width()<<endl;
  cout<<"Image matrix is:"<<endl;
  p.get_matrix();
}