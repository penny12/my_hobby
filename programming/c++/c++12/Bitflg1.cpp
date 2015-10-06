#include <iostream>
using namespace std;

int Bit(int x)
{
  return 1 << x;
}

const int SHOW_X = Bit(0);
const int SHOW_Y = Bit(1);
const int SHOW_Z = Bit(2);

void show(int flags)
{
  cout << ((flags & SHOW_X) != 0 ? 'X' : 'x')
       << ((flags & SHOW_Y) != 0 ? 'Y' : 'y')
       << ((flags & SHOW_Z) != 0 ? 'Z' : 'z')
       << endl;
}

int main()
{
  show(0);
  show(SHOW_X);
  show(0xff^(~(SHOW_X | SHOW_Z)));
  int flg = ~0;
  show(flg);
  // flg &= ~SHOW_X;
  // show(flg);
  flg ^= (SHOW_X bitor SHOW_Z);
  show(flg);
}
