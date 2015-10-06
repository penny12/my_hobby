#include "FileException.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void Open(ifstream& file, const char* filename)
{
  file.open(filename);
  if(!file.is_open())
  {
    throw FileException("can't open file.");
  }
}

void GetLine(ifstream& file, string& line)
{
  getline(file, line);
  if(file.fail())
  {
    FileException e("cant load data from file.");
    throw e;
  }
}
 
int main()
{
  try
  {
    ifstream file;
    Open(file, "ltest.txt");

    string line;
    GetLine(file, line);
    cout << line << endl;
  }
  catch(const FileException& e)
  {
    cerr << e.What() << endl;
    return EXIT_FAILURE;
  }
}
