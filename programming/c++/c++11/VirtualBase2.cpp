#include <iostream>
using namespace std;

class V
{
public:
  V() : count(0) {}
protected:
  int count;
};

class A : virtual public V
{
public:
  void inc() { count++; }
};

class B : virtual public V
{
public:
  void inc() { count++; }
};

class X : public A, public B
{
public:
  int get() { return count; }
};

int main()
{
  X x;
  x.B::inc();
  cout << x.get() << endl;
  x.A::inc();
  cout << x.get() << endl;
}
