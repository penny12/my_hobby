#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  fstream file;

  file.open("test.txt", ios::out);
  file << "asdf\nfdas" << endl;
  file.close();

  file.open("test.txt", ios::in);
  string str;
  getline(file, str);
  file.close();
  cout << str << endl;

}
