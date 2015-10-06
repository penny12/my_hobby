#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
using namespace std;

class CManiac
{
private:
  char *m_pc;

public:
  virtual ~CManiac() { delete[] m_pc; }
  CManiac() : m_pc(new char[1]) {}
  CManiac(const CManiac& rmaniac) : m_pc(new char[1]) {
    strncpy(m_pc, rmaniac.m_pc, 1);
  }
  string str;
};

int main()
{
  // vector<CManiac> v;
  // v.resize(3);
  // return 0;
  // int aiTable[10];

  // for(int *p = aiTable, i = 0; p < &aiTable[(sizeof aiTable / sizeof aiTable[0])]; ++p, ++i)
  // {
  //   cout << i << endl;
  // }

  vector<int> v;
  v.resize(10);
  for(vector<int>::iterator itiElement = v.begin(); itiElement != v.end(); ++itiElement)
  {
    *itiElement = 3;
  }

  vector<CManiac* > vm;
  CManiac *a = new CManiac();
  CManiac *b = new CManiac();
  CManiac *c = new CManiac();
  vm.push_back(a);
  vm.push_back(b);
  vm.push_back(c);
  // vm.resize(3);
  for(vector<CManiac* >::iterator /**/ first = vm.begin(); first != vm.end(); ++first)
  {
    (*first)->str = "asdfa";
  }

  for(vector<CManiac* >::iterator /**/ first = vm.begin(); first != vm.end(); ++first)
  {
    cout << (*first)->str << endl;
  }
}
