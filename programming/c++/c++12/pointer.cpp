#include <iostream>
using namespace std;

class A
{
public:
  typedef int* const INT;

private:
  
};

typedef int* const  INT;

int main()
{
  INT a = new int;
  *a = 30;
  cout << *a << endl;
}
