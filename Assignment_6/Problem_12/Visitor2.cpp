#include <iostream>
using namespace std;
class Visitor;
class Member
{
  protected:
  int membershipId;
  string name,joiningDate;
  public:
  virtual void acceptVisitor(Visitor*)=0; // pure virtual method
  virtual void display()=0;
  string getName() // returns name
  {
    return name;
  }
  int getMembershipId() // returns membership id
  {
    return membershipId;
  }
  void displayAnnualCharges() // displays annual charges
  {
    this->display();
  }
  void displayDetails() // displays details
  {
    cout<<"Name:"<<getName()<<endl;
    cout<<"Membership Id: "<<getMembershipId()<<endl;
    cout<<"Joining Date: "<<joiningDate<<endl;
  }
};
class PremiumMember : public Member
{
  public:
  static const double monthlyCharges;
  PremiumMember(int x,string n,string d)
  {
    membershipId=x;
    name=n;
    joiningDate=d;
  }
  void acceptVisitor(Visitor*);
  void display()
  {
    cout<<"Annual charges is: "<<(monthlyCharges*12)<<endl;
  }
};
class OrdinaryMember : public Member
{
  public:
  static const double monthlyCharges;
  OrdinaryMember(int x,string n,string d)
  {
    membershipId=x;
    name=n;
    joiningDate=d;
  }
  void acceptVisitor(Visitor* v);
  void display()
  {
    cout<<"Annual charges is: "<<(monthlyCharges*12)<<endl;
  }
};
const double PremiumMember::monthlyCharges = 100.0; // static variable initialization
const double OrdinaryMember::monthlyCharges = 50.0;// static variable initialization
class Visitor 
{
  public:
  virtual void visit(PremiumMember* pm) = 0;
  virtual void visit(OrdinaryMember* om) = 0;
};
class InvitationVisitor : public Visitor
{
  public:
  void visit(PremiumMember* pm) 
  {
    cout<<"Hello "<<pm->getName()<<", We have a special holiday package for you! A one-week tour of the Big Island of Hawaii with a unique 5-day cruise itinerary!\n";
  }
  void visit(OrdinaryMember* om) 
  {
    cout<<"Hello "<<om->getName()<<", Pack your bags for the Andaman Islands.We have a special 2-day tour package for you!\n";
}
};
void PremiumMember :: acceptVisitor(Visitor *v)
{
    v->visit(this);
}
void OrdinaryMember :: acceptVisitor(Visitor *v)
{
    v->visit(this);
}
 int main() {
Member* m = new PremiumMember(1000, "Suresh", "05-03-2022");
Visitor* visitor = new InvitationVisitor();
m->acceptVisitor(visitor); //should print out the invitation!
m->displayAnnualCharges();
}