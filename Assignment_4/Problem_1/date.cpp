#include<iostream>
#include<string>
using namespace std;
class Date
{
	int dd,mm;
  mutable int yy; 
	string d;
	public:
	Date(int d=0,int m=0,int y=0);
	bool check_leap() const;
	void add_year(int o, int& flag);
  void date_display() const;
  int get_year() const;
  void set_year(int y);
  int get_day() const;
  void set_day(int d);
  int get_month() const;
  void set_month(int m);
  string get_string() const;
  void set_string();
};
Date::Date(int d,int m,int y) // constructor
{
    set_day(d);
    set_month(m);
    set_year(y);
}
void Date::set_day(int d) // setting the date
{  
  if (get_day() < 1 && get_day() > 31)
    cout << "The day is invalid" << endl;
  else
    dd=d;    
}
void Date::set_month(int m) //setting the month
{
   if (m < 1 && m > 12)
    cout << "The month is invalid" << endl;
   else
    mm = m;
}
void Date::set_string() //set the date
{  
d=to_string(get_day())+"/"+to_string(get_month())+"/"+to_string(get_year());
}
string Date::get_string() const // returns string
{
  return d;
}
void Date::set_year(int y){yy=y;} //sets the year
int Date::get_day() const {return dd;} // returns day
int Date::get_month() const {return mm;} // returns month
int Date::get_year() const {return yy;} // returns year
bool Date::check_leap() const // check if the year is a leap year
{
    if (get_year()%400==0||(get_year()%4==0 && get_year()%100!=0))
     return true;
    else
     return false;    
}
void Date::add_year(int o, int& flag) //method to add years
{
  int y=get_year()+o;
  if(get_day()==29 && get_month()==2 && (y%400==0 ||(y%4==0 && y%100!=0)))
  {
    dd=1;mm=3;
  }
  set_year(y);
  flag++;
  set_string();
}
void Date:: date_display() const // displays date
{
 cout<<"The date is:"<<get_string()<<endl;
}
int main()
{
  	int d,m,y,c,n,i=1;
    static int flag=0;
  	cout<<"Enter the day, month and year"<<endl;
  	cin>>d>>m>>y;
  	Date dt(d,m,y);
    while(i)
    {
      cout<<"Enter 1 to check whether it is a leap year or not, 2 to add years to a date and 3 to display the date"<<endl;
      cout<<"Enter your choice"<<endl;
      cin>>c;
      switch(c)
      {
        case 1: if(dt.check_leap())
            cout<<"It is a leap year"<<endl;
          else
            cout<<"Not a leap year"<<endl;
        break;
        case 2: cout<<"Enter the number of years to add"<<endl;
        cin>>n;
        dt.add_year(n,flag);
        break;
        case 3: if (flag==0)
        {
          dt.set_string();
          cout<<dt.get_string()<<endl;
        }
        else
        {
          cout<<dt.get_string()<<endl;
        }
        break;
        default:cout<<"Invalid choice!"<<endl;   
      }
      cout<<"Do you want to continue ?(1/0)"<<endl;
      cin>>i;
  } 	
}