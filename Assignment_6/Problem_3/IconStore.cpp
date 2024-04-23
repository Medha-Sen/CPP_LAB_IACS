#include <iostream>
using namespace std;
class Icon
{ //abstract
  public:
  virtual void type()=0;
  virtual Icon* clone() const =0;
};
class MenuIcon : public Icon
{
  public:
  MenuIcon()
  {
   cout<<"0-Menu Icon is created"<<endl;
  }
  MenuIcon(const MenuIcon& m) { }
  ~MenuIcon() { }
  Icon* clone() const
  {
   return new MenuIcon(*this); // invokes implicit copy constructor
  }
  void type()
  {
    cout<<"MenuIcon"<<endl;
  }
};
class SearchIcon : public Icon
{
  public:
  SearchIcon()
  {
   cout<<"1-Search Icon is created"<<endl;
  }
  SearchIcon(const SearchIcon& s) { }
  ~SearchIcon() { }
  Icon* clone() const
  {
   return new SearchIcon(*this);// invokes implicit copy constructor
  }
  void type() 
  {
    cout<<"SearchIcon"<<endl;
  }
};
class OpenIcon : public Icon
{
  public:
  OpenIcon()
  {
   cout<<"2-Open Icon is created"<<endl;
  }
  OpenIcon(const OpenIcon& o) { }
  ~OpenIcon() { }
  Icon* clone() const
  {
   return new OpenIcon(*this);// invokes implicit copy constructor
  }
  void type() 
  {
    cout<<"OpenIcon"<<endl;
  }
};
class CloseIcon : public Icon
{
   public:
   CloseIcon()
  {
   cout<<"3-Close Icon is created"<<endl;
  }
  CloseIcon(const CloseIcon& m) { }
  ~CloseIcon() { }
   Icon* clone() const
  {
   return new CloseIcon(*this);
  }
  void type() 
  {
    cout<<"CloseIcon"<<endl;
  }
};
class IconStore
{
  public:
  Icon* arr[4];
  IconStore()
  {
   arr[0]=new MenuIcon();
   arr[1]=new SearchIcon();
   arr[2]=new OpenIcon();
   arr[3]=new CloseIcon();
  }
  Icon* client_request(int n)
  {
    switch(n)
      {
        case 0: return arr[0]->clone();
        case 1: return arr[1]->clone(); 
        case 2: return arr[2]->clone();
        case 3: return arr[3]->clone();
        default: cout<<"Wrong choice.No such Icon exists!"<<endl; return nullptr;       
      }
  }
};
int main() {
  IconStore ic;
  int c;
  cout<<"Enter client request for icon (0-3)"<<endl;
  cin>>c;
  Icon* i=ic.client_request(c);
  if(i!=nullptr)
  i->type();
}
