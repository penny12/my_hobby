#include <iostream>
using namespace std;

class ABase
{
public:
  virtual ~ABase() {}
  virtual void Hoge() = 0;
};

class A1 : public ABase
{
public:
  virtual void Hoge()
  {
    cout << "A1::Hoge()" << endl;
  }
};

class A2 : public ABase
{
public:
  virtual void Hoge()
  {
    cout << "A2::Hoge()" << endl;
  }
};

class C :
  public A1,
  public A2
{
  // virtual void Hoge()
  // {
  //   cout << "C::Hoge()" << endl;
  // }
};

int main()
{
  C c;

  // A1 &a1 = c;
  // A2 &a2 = c;

  // a1.Hoge();
  // a2.Hoge();
  
  // c.A1::Hoge();
  // c.A2::Hoge();
  ABase &a1 = static_cast<A1&>(c);
  ABase &a2 = static_cast<A2&>(c);
  a1.Hoge();
  a2.Hoge();

  return 0;
}
