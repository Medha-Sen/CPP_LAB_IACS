#include<iostream>
using namespace std;
class AI
{
	public:
	bool usesKG;
	AI(bool x=false)
	{
		usesKG=x;
	}
};
class Neural : public AI
{
	public:
	void train()
	{
		cout<<"Inside function train()"<<endl;
	}
};
class Symbolic : public AI
{
	public:
	void reason()
	{
		cout<<"Inside function reason()"<<endl;
	}
};
class NeuroSymbolic : public Neural, public Symbolic
{
  public:
  void message()
  {
   cout<<"Inside NeuroSymbolic class"<<endl;
  }
};
int main()
{
	NeuroSymbolic* ai_ns=new NeuroSymbolic();
	ai_ns->reason();
	AI* ai;
  ai=ai_ns;
  bool b=ai->usesKG;
}
