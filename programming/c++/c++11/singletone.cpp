#include <iostream>
using namespace std;

class A
{
public:
  static A* Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new A;
      return s_pInstance;
    }
    return s_pInstance;
  };

  static A* s_pInstance;

  void show() { cout << "Asad" << endl; }

private:
  A(){}
};

// typedef A TheA;

A* A::s_pInstance = 0;

int main()
{
  A::Instance()->show();
}
