#include <iostream>
#include<fstream>
#include<time.h>
using namespace std;
class Command
{
  public:
  virtual void execute()=0;
  virtual void log()=0;
};
class DisplayFileCommand : public Command
{
  public:
  string f;
  DisplayFileCommand(string n)
  {
    f=n;
  }
  void execute()
  {
    string line;
    fstream fread;
    fread.open(f,ios::out | ios::in);
    while(fread)
      {
         getline(fread, line);
        cout << line << endl;
      }
    fread.close();
    log();
  }
  void log()
  {
    fstream f;
    f.open("log.txt",ios::app);
    f<<"DisplayFileCommand was called\n";
    f.close();
  }
};
class HelpCommand : public Command
{
  public:
  void execute()
  {
    cout<<"*******Help Manual********\n";
    cout<<"1. DisplayFileCommand will display the contents of a file requested by the client\n";
    cout<<"2. ShowTimeCommand displays the current time\n";
    cout<<"There is a log file keeping track of the order of execution of commands\n";
    log();
  }
  void log()
  {
    fstream f;
    f.open("log.txt",ios::app);
    f<<"HelpCommand was called\n";
    f.close();
  }
};
class ShowTimeCommand : public Command
{
  public:
  void execute()
  {
     time_t my_time = time(NULL);
     cout<< ctime(&my_time)<<endl;
     log();
  }
  void log()
  {
    fstream f;
    f.open("log.txt",ios::app);
    f<<"ShowTimeCommand was called\n";
    f.close();
  }
};
int main() {
Command* c1 = new ShowTimeCommand();
c1->execute();
c1 = new DisplayFileCommand("./streetnames.txt");
c1->execute();
c1 = new HelpCommand();
c1->execute();
c1 = new ShowTimeCommand();
c1->execute();
ifstream f;
string lines;
f.open("log.txt");
if (f.is_open())
{
    while (getline(f,lines))
    {
      cout << lines << '\n';
    }
    f.close();
  }
  else cout << "Unable to open file"; 
}