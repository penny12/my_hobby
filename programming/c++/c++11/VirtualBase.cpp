#include <iostream>
using namespace std;

class A
{
public:
  virtual void Foo() = 0;
  virtual int get() = 0;
  A() : count(0) { }

protected:
  int count;
};

class B : virtual public A
{
public:
  // virtual void Foo() { cout << "Foo" << endl; }
  // static void Bar(B& b) { b.Foo(); }
  // void inc() { count++; }
  // void clear() { count = 0; }
  // int get() { return count; }
  void inp() { count++; }
};

class C : virtual public A
{
public:
  virtual void Foo() { cout << "FooC" << endl; }
  static void Bar(C& c) { c.Foo(); }
  void inc() { count++; }
  void clear() { count = 0; }
  int get() { return count; }
};

class V : public B, public C
{
};

void get(A& a)
{
  a.Foo();
}

int main()
{
  // B b;
  // get(b);
  // b.inc();
  // cout << b.get() << endl;
  C c;
  get(c);
  c.inc();
  cout << c.get() << endl;
  // cout << b.get() << endl;
  V v;
  v.inc();
  v.inp();
  cout << v.get() << endl;

  // A a;
  // cout << a.get() << endl;
}
