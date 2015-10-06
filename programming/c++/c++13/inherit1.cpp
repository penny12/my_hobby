#include <iostream>
using namespace std;

class A
{
public:
  virtual ~A() {}
  virtual void AShow() = 0;
};

class B
{
public:
  virtual ~B() {}
  virtual void BShow() = 0;
};

class C :
  public A,
  public B
{
public:
  virtual void AShow() { cout << "C::AShow" << endl; }
  virtual void BShow() { cout << "C::BShow" << endl; }
};

int main()
{
  C c;

  // c.AShow();
  // c.BShow();

  A &a = c;
  a.AShow();

  B &b = c;
  b.BShow();
}
