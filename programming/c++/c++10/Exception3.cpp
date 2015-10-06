#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void Error()
{
  try
  {
    throw 1;
  }
  catch(int error)
  {
    throw "error";
  }
  catch(const char* error)
  {
    cout << "this way Error() " << endl;
  }
}

int main()
{
  try
  {
    Error();
  }
  catch(const char* error)
  {
    cout << "other way main()" << endl;
  }

}
