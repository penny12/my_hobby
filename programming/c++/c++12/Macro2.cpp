#include <iostream>
#include <cassert>
using namespace std;

#define ARRAY_SIZE(array) (sizeof array / sizeof *array)

int main()
{
  int array[100];
  cout << ARRAY_SIZE(array) << endl;
  do
  {
  }while(false);
  assert(false);
  cout << "asd" << endl;
}
