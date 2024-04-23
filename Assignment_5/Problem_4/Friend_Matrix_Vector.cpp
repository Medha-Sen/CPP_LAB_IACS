#include <iostream>
#include<iomanip>
using namespace std;
class Vector;
class Matrix
{
  const int m;
  const int n;
  int *arr1;
  public:
  Matrix(int r,int c); 
  inline int rows(void) const { return m;} // returns no. of rows
  inline int cols(void) const { return n;}// returns no. of columns
  int getValue(int r, int c) const; // returns matrix element value
  void setValue(int v, int r, int c); //sets values
  friend Vector& operator*(const Matrix&, const Vector&); //friend
  inline int& get(int r, int c) const //returns matrix element
  {
    return arr1[n * r + c];
  }
  void print(const Matrix& m) const
  {
    std::cout << std::fixed << std::setprecision(1);
    for (int r = 0; r < m.rows(); ++r) {
    for (int c = 0; c < m.cols(); ++c) {
    std::cout << (c > 0 ? " " : "") << std::setw(4);
    std::cout << m.getValue(r, c);
    }
    std::cout << std::endl;
    }
  }
};
 Matrix::Matrix(int r,int c):m(r),n(c)
  {
    arr1=new int[m*n];
    int v;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<"Enter a value in the matrix\n";
        cin>>v;
        setValue(v,i,j);
      }
    }
  } 

int Matrix::getValue(int r, int c) const
{
  return get(r, c);
}
void Matrix::setValue(int v, int r, int c)
{
  get(r, c) = v;
}
class Vector
{
  private:
  int l;
  int *arr2;
  public:
  Vector(int len=0,int flag=1)
  {
    l=len;
    arr2=new int[l];
    if(flag==1)
    {
    for(int i=0;i<l;i++)
    {
       cout<<"Enter a value in the vector\n";
       cin>>arr2[i];
    }
    }
  }
  int get_length() const // returns vector length
  {
    return l;
  }
  void print() const // prints vector value
  {
    cout<<"Result is"<<endl;
    for(int i=0;i<l;i++)
      {
        cout<<arr2[i]<<endl;
      }
  }
  friend Vector& operator*(const Matrix&, const Vector&);
};
Vector& operator*(const Matrix& M,const Vector& V)
{
  if(M.n==V.l) // checks dimensions
  {
    static Vector vv(M.m,0);
    for(int i=0;i<M.rows();i++)
      {
        for(int j=0;j<M.cols();j++)
          {
            vv.arr2[i]=vv.arr2[i]+(M.getValue(i,j)*V.arr2[j]);
          }
      }
    return vv;
  }
  else
  {
    static Vector vv(0,0);
    return vv;
  }
}
int main() {
  int m=2,n=2,k=2;
  cout<<"Enter m, n and k"<<endl;
  cin>>m>>n>>k;
  if(n!=k)
    cout<<"Multiplication not possible\n";
  else
  {
    Matrix mat(m,n);
    Vector vec(k,1);
    Vector v_res=mat*vec;
    if(v_res.get_length()==0)
     cout<<"Multiplication not possible!!\n";
    else
    {
     v_res.print();
    }
  }
  //mat.print(mat);
}