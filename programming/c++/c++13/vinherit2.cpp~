#include <iostream>
using namespace std;

class ABase
{
public:

  virtual ~ABase() {}
  void set(int num) { m_num = num; }
  virtual void show() = 0;

protected:

  int m_num;
};

class A1 : virtual public ABase {};
class A2 : virtual public ABase {};

class C :
  public A1,
  public A2
{
public:
  virtual void show() { cout << A1::m_num << "," << A2::m_num << endl; }
};

int main()
{
  C c;

  A1 &a1 = c;
  A2 &a2 = c;

  a1.set(3);
  c.show();

  a2.set(5);
  c.show();
}


  
