#include <iostream>
using namespace std;
class Sentence
{
  string s;
  public:
  Sentence(string str="")
  {
    s=str;
  }
  void print() // prints the sentence
  {
    cout<<s<<endl;
  }
  void changeCase() // changes the case 
  {
    int l= s.length();
    for (int i = 0; i < l; i++) {
      if (s[i] >= 'a' && s[i] <= 'z')
         s[i] = s[i] - 32;
      else if (s[i] >= 'A' && s[i] <= 'Z')
         s[i] = s[i] + 32;
    }
  }
};
class Paragraph
{
  int n;
  Sentence *arr;
  public:
  Paragraph(int n)
  {
    arr= new Sentence[n];
     cout<<"Enter "<<n<<" sentences in the paragraph"<<endl;
    for(int i=0;i<n;i++)
    {
      string str;
      getline(cin,str);
      arr[i]=Sentence(str);
    }
  }
  void print() // prints the paragraph
  {
    for(int i=0;i<n;i++)
      {
        arr[i].print();
      }
  }
  void changeCase() // changes the case sentence-wise
  {
    for(int i=0;i<n;i++)
      {
        arr[i].changeCase();
      }
  }
};
int main() {
  string str;
  int n;
  cout<<"Enter the number of lines in the paragraph\n";
  cin>>n;
  cout<<"Enter a standalone sentence."<<endl;
  getline(cin >> ws,str);
  Sentence s(str);
  Paragraph p(n);
  cout<<"sentence: After case change"<<endl;
  s.changeCase();
  s.print();
  cout<<"paragraph: After case change"<<endl;
  p.changeCase();
  p.print();
}