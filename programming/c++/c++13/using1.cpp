#include <iostream>
using namespace std;

class Base
{
public:
  static void Value(char ch) { cout << ch << endl; }
  static void Value(const char* ch) { cout << ch << endl; }
};

class A : virtual public Base
{
public:
  static void Value(char ch) { cout << (int)ch << endl; }

  using Base::Value;  
};

int main()
{
  A::Value('A');
  A::Value("adsas");
}
