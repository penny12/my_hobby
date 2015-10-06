#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void tes1()
{
  throw "asdf";
}

void open(ifstream &file, const char* filename)
{
  file.open(filename);
  if(!file.is_open())
  {
    throw "can't open file";
  }
  return;
}

void getLine(ifstream &file, string &line)
{
  getline(file, line);
  if(file.fail())
  {
    throw "can't load from file";
  }
}

int main()
{
  try
  {
    ifstream file;
    open(file, "testp.txt");
    string line;
    getLine(file, line);
    cout << line << endl;
  }
  catch (const int error) 
  {
    cerr << "int: " << error << endl;
    return EXIT_FAILURE;
  }
  // catch (const char* error) 
  // {
  //   cerr << "char: " << error << endl;
  //   return EXIT_FAILURE;
  // }

  catch (const char* error) 
  {
    cerr << "char: " << error << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
