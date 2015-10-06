#include <iostream>
#include <boost/scoped_array.hpp>
using namespace std;

int main()
{
  boost::scoped_array<int> x(new int[3]);
  for(int i = 0; i < 3; ++i)
  {
    x[i] = i;
  }

  for(int i = 0; i < 3; ++i)
  {
    cout << x[i] << " " << flush;
  }
  cout << endl;

  return 0;
}
