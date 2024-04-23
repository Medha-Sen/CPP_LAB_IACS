#include <iostream>
using namespace std;
int main() {
  unsigned int i = 1;
  char *y=(char *)&i;
  if(*y+48=='1')
    cout<<"Little Endian"<<endl;
  else
   cout<<"Big Endian"<<endl;
}