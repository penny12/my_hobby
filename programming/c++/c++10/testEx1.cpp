#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
  cout << "EXIT_FAILURE : " << EXIT_FAILURE << endl;
  cout << "EXIT_SUCCESS : " << EXIT_SUCCESS << endl;
  
  try
  {
    throw "asdf";
    throw 3;
  }
  catch(int e)
  {
    cout << "int: " << e << endl;
    return 1;
  }
  catch(string e)
  {
    cout << "string: " << e << endl;
    return 1;
  }
  return 0;
}
