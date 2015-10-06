#include <iostream>
using namespace std;

int main()
{
  int a = 3;
  double b = 5.34;
  char c = 'f';
  void *p;

  p = &a;
  cout << *static_cast<int*>(p) << endl;
  p = &b;
  cout << *static_cast<double*>(p) << endl;
  p = &c;
  cout << *static_cast<char*>(p) << endl;

#ifdef WINDOWS
  cout << "Windows" << endl;
#elif defined(MAC)
  cout << "Mac" << endl;
#else
  cout << "Linux" << endl;
#endif
  

  return 0;
}
