#include <iostream>
using namespace std;

class A
{
  friend class B;
  A() : a(3) {}
  int a;
};

class B : public A
{
public:
  void get() { cout << a << endl; }
};

int main()
{
  B b;
  b.get();
}
