#include <iostream>
using namespace std;

class ABase
{
public:

  ABase(int num) : m_num(num) { }
  virtual ~ABase() {}
  void show() { cout << m_num << endl; }

protected:

  int m_num;
};

class A1 : virtual public ABase { public: A1() : ABase(1) { } };
class A2 : virtual public ABase { public: A2() : ABase(2) { } };

class C :
  public A1,
  public A2
{
public:
  C() : ABase(3){ }
};

int main()
{
  A1 a1; a1.show();
  A2 a2; a2.show();
  C c;   c.show();
}


  
