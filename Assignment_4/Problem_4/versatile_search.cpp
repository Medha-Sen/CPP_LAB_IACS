#include <iostream>
using namespace std;
typedef bool (*comp)(void*,void*);// typedef for function pointers of type comp
bool compareInt(void* x, void* y)// compares type int
{
    if(*((int*)x) == *((int*)y))
        return true;
    return false;
}
bool compareDouble(void* x, void* y) // compares type double
{
    if(abs(*(double*)x - *(double*)y) < 0.000001)
        return true;
    return false;
}
int linear_search(void* p_target, void* arr, int N,comp pf,void* get_next(void*)) // implementation of linear search
{
  void* temp=arr;
  for(int i=0;i<N;i++)
  {
    if((*pf)(temp,p_target))
      return i;
    temp=get_next(temp);
  }
  return -1;
}
void* get_next_Int(void* x) // returns next int in the array
{
    return (void*)((int*)x+1);
}

void* get_next_Double(void* x) // returns next double in array
{
    return (void*)((double*)x+1);
}
int main() {
 int arrInt[]={1,5,-2,20,6};
 int targetInt=-2;
  void* p_target=&targetInt;
  int N= sizeof(arrInt)/sizeof(int);
  comp pfInt=(comp)compareInt;//Typecasting 
  int index=linear_search(p_target, arrInt,N,pfInt,get_next_Int);
  cout<<"The index for the first array is "<<index<<endl;

  double arrDouble[]={2.3,4.6,-1.2};
  double targetDouble=2.3;
  p_target=&targetDouble;
  N= sizeof(arrDouble)/sizeof(double);
  comp pfDouble=(comp)compareDouble;//Typecasting 
  index=linear_search(p_target, arrDouble,N,pfDouble,get_next_Double);
  cout<<"The index for the first array is "<<index<<endl;
  return 0;
}