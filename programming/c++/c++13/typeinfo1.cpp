#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>
using namespace std;

void showType(const ostream& ostr)
{
  cout << typeid(ostr).name() << endl;
}

int main()
{
  fstream fstr;
  ofstream ofstr;
  stringstream sstr;
  ostringstream osstr;

  showType(fstr);
  showType(ofstr);
  showType(sstr);
  showType(osstr);
}
