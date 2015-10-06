#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  ifstream file;
  try
  {
    file.open("tdet.txt");
    if(!file.is_open())
    {
      throw "cant open test.txt";
    }
  }
  catch (const char* error)
  {
    cerr << error << endl;
    return EXIT_FAILURE;
  }
  return 0;
}
