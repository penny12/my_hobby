#include <iostream>
using namespace std;

class A
{
public:
  A() : SIZE(100) {}

  void show() { cout << "SIZE: " << SIZE << " P: " << P << endl; }
private:
  const int SIZE;
  static const int P = 10;
};

int main()
{
  A a;
  a.show();
}
