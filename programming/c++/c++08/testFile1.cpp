#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  fstream file;
  
  // file.open("test.txt", ios::out);
  // file << "aasdf" << endl;
  // file.close();

  file.open("test.txt", ios::in | ios::out);
  string str;
  // getline(file, str);
  // cout << str << endl;
  // file << "assdaads" << endl;
  getline(file, str);
  cout << str << endl;
  file << "as" << endl;
  file.close();

  int p = 0123;
  cout << p << endl;
}