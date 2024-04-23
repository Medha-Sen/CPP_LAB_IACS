#include <iostream>
#include<string>
using namespace std;
struct Course{ 
const char* name;
unsigned short sem; 
unsigned int limit; 
unsigned int course_id;
};
void check_semester(const Course & c1, const Course & c2)
{ // checking if two courses are offered in the same semester
  if(c1.sem==c2.sem)
  {
    cout<<"True"<<endl;
  }
  else
  {
    cout<<"False"<<endl;
  }
}
void check_identical(Course & c1, Course & c2)
{ //checking if two courses are identical
  if(!(c1.name==c2.name) && c1.sem==c2.sem && c1.limit==c2.limit)
  {
    cout<<"True"<<endl;
  }
  else
  {
    cout<<"False"<<endl;
  }
}
void initialize_details(Course c[],int n)
{ //initializing the data members to default values
  for(int i=0;i<n;i++)
  {
   c[i].name=(char*)malloc(sizeof(char)*100);
   c[i].sem=0;
   c[i].limit=0;
   c[i].course_id=0;
  }
}
void update_details(Course & c)
{ // inserting values for a particular course record
    char *nm;
    unsigned int id,l;
    unsigned short sem;  
    nm=(char*)malloc(sizeof(char)*100);
    cout<<"Enter the name of the course\n";
    cin >> nm;   
    c.name=nm;
    cout<<"Enter the course id\n";
    cin>>id;
    c.course_id=id;
    cout<<"Enter the semester when this course is offered\n";
    cin>>sem;
    c.sem=sem;
    cout<<"Enter the limit of students who can enroll in this course\n";
    cin>> l;
    c.limit=l;
}
void print_details(Course & c)
{  //printing the details of a course
  cout<<"********************************"<<endl;
  cout<<"Name of the course is: "<<c.name<<endl;
  cout<<"Course id is: "<<c.course_id<<endl;
  cout<<"The course is offered in semester: "<<c.sem<<endl;
  cout<<"Maximim number of students allowed is: "<<c.limit<<endl;  
  cout<<"********************************"<<endl;      
}
int main() {
  int n,ch,i,j,q=1;  
  cout << "Enter the number of courses\n";
  cin>>n;
  Course c[n];//Array of structures. each member is of type Course
  initialize_details(c,n);
  for(int i=0;i<n;i++)
  {      
    update_details(c[i]);//intial update 
  }
  while(q)
  {
  cout<<"Enter 1 to check if two courses are in the same semester"<<endl;
  cout<<"   2 to check if two courses are identical"<<endl;
  cout<<"   3 to update the details of a course"<<endl;
  cout<<"   4 to print the details of a course"<<endl;
  cin>>ch;
  switch(ch)
  {
    case 1: cout<<"Enter the indexes of the courses"<<endl;
    cin>>i>>j;
    check_semester(c[i],c[j]);
    break;
    case 2: cout<<"Enter the indexes of the courses"<<endl;
    cin>>i>>j;
    check_identical(c[i],c[j]);
    break;
    case 3: cout<<"Enter the index of the course"<<endl;
    cin>>i;
    update_details(c[i]);
    break;
    case 4: cout<<"Enter the index of the course"<<endl;
    cin>>i;
    print_details(c[i]);
    break;
    default:cout<<"Wrong option. Enter again!";
  }
  cout<<"Want to continue ?(0/1)"<<endl;
  cin>>q;
 }
}
