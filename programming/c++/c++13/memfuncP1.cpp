#include <iostream>
using namespace std;

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (*array))

class Calc
{
public:

  Calc(int a, int b) : m_a(a),
                       m_b(b)
  { }

  int sum() { return m_a + m_b; }
  int sub() { return m_a - m_b; }
  int mul() { return m_a * m_b; }
  int div() { return m_a / m_b; }

  typedef int (Calc::*FpOp)();
  static const FpOp CalcOp[];
  static const char* const calcName[];

  void Run();

private:
  int m_a, m_b;
};

const Calc::FpOp Calc::CalcOp[] =
{
  &Calc::sum, &Calc::sub, &Calc::mul, &Calc::div
};

const char* const Calc::calcName[] = 
{
  "sum", "sub", "mul", "div"
};

void Calc::Run()
{
  for(int i = 0; i < ARRAY_SIZE(CalcOp); ++i)
  {
    cout << calcName[i] << ": " << (this->*CalcOp[i])() << endl;
  }
  cout << endl;
}

int main()
{
  Calc c(3, 6);
  c.Run();
  Calc p(10, 5);
  p.Run();
}

