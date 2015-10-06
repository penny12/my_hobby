#include <iostream>
using namespace std;

class A
{
public:
  A() : p(3) { }
  void show() { this->unk(); }
  void unk() { cout << "unk" << endl; }
  void calc() { (*this).p += 5; }

  int p;
};

int main()
{
  A a;
  cout << &a << endl;
  a.show();
  cout << a.p << endl;
  a.calc();
  cout << a.p << endl;
  
  // A b;
  // cout << &b << endl;
  // b.show();
}
