#include <iostream>
using namespace std;

#define ARRAY_SIZE(array) (sizeof *ARRAY_SIZE_(&(array)))

template <typename T, size_t N>
char (*ARRAY_SIZE_(T (*)[N]))[N];

int main()
{
  int p[15];
  double q[340];
  cout << ARRAY_SIZE(q) << endl;
}
