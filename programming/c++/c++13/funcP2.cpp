#include <iostream>
#include <cassert>
using namespace std;

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (*array))

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

int (*const CALCARR[])(int, int) =
{
  sum, sub, mul, div
};

const char* const name[] =
{
  "sum", "sub", "mul", "div"
};

class Calc
{
public:

  Calc(int a, int b) : SIZE(ARRAY_SIZE(CALCARR)),
                       m_a(a),
                       m_b(b)
  { }

  void Run()
  {
    for(int i = 0; i < SIZE; ++i)
    {
      cout << name[i] << ": " << CALCARR[i](m_a, m_b) << endl;
    }
  }

private:
  int SIZE;
  int m_a, m_b;
};

int main()
{
  Calc a(3, 5);
  a.Run();
  cout << endl;
  Calc b(13, 5);
  b.Run();
}
