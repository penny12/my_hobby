#include <iostream>
using namespace std;

class ABase
{
public:
  virtual void show() = 0;
};

class A1 : virtual public ABase
{
public:
  virtual void show() { cout << "A1::show()" << endl; }
};

class A2 : virtual public ABase
{
public:
  virtual void show() { cout << "A2::show()" << endl; }
};

class C :
  public A1,
  public A2
{
public:
  // virtual void show() { cout << "C::show()" << endl; }
};

int main()
{
  C c;
  ABase &ab = c;
  ab.show();
}
                                
