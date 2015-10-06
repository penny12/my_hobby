#include <iostream>
using namespace std;

class A
{
public:
  virtual int getCount() = 0;
  A() { ++count; }
  ~A() { --count; }

protected:
  static int count;
};

int A::count;

class B : public A
{
public:
  int getCount() { return count; }
  static int getU() { return count; }
  static int g() { getU(); }
};

int main()
{
  B b;
  // cout << b.getCount() << endl;
  { B b;
  cout << B::g() << endl;
  }

  // {
  //   B b;
  //   cout << b.getCount() << endl;
  // }

  // cout << b.getCount() << endl;
  cout << B::g() << endl;

  return 0;
}
