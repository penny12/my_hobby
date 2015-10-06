#include <iostream>
using namespace std;

int get(int a)
{
  return a;
}

int main()
{
  int (*const fp)(int) = get;
  cout << fp(5) << endl;
}
