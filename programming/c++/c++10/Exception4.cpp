#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void open(ifstream &file, const char* filename)
{
  try
  {
    file.open(filename);
    throw "error";
    if(!file.is_open())
    {
      throw "error";
    }
    file.close();
  }
  catch(...)
  {
    file.close();
    throw;
  }
}

int main()
{
  try
  {
    ifstream file;
    open(file, "test.txt");
  }
  catch(const char* error)
  {
    cout << "this" << endl;
    cerr << error << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
