#include <iostream>
using namespace std;

#define ARRAY_SIZE(array) ( sizeof (array) / sizeof (*array))

class A
{
public:

  A(int a, int b) : m_x(a), m_y(b) { }

  void IncX();
  void IncY();
  void Get();
  void show();

  inline void IncPointMem(int A::*mp)
  {
    ++(this->*mp);
  }

private:

  int m_x, m_y;
};

void A::IncX()
{
  IncPointMem(&A::m_x);
}

void A::IncY()
{
  IncPointMem(&A::m_y);
}

void A::show()
{
  cout << this->m_x << ", " << this->m_y << endl;
}

int main()
{
  A a(3, 4);
  a.show();
  a.IncX();
  a.show();
  a.IncY();
  a.show();
}
