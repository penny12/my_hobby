#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int a = 0x90;
  char *str = new char[100];
  vector<int> v;
  
  sprintf(str, "0x%x\n", a & 0x70);
  cout << str << endl;

  int num = 105503;
  for(int i = 1; i != 0; i <<= 1)
  {
    if((num & i) == 0)
    {
      v.push_back(0);
    } else {
      v.push_back(1);
    }
  }
  for(vector<int>::iterator first = v.end(); first != v.begin(); --first)
  {
    cout << *first;
  }
  cout << endl;
}
