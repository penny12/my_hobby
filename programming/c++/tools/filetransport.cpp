#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;


int main(int argc, char** argv)
{
  boost::scoped_array<int> x(new int);
  // boost::scoped_ptr<int> x;
  for(int i = 0; i < 10; ++i)
  {
    x[i] = i;
  }

  for(int i = 0; i < 10; ++i)
  {
    cout << x[i] << " " << flush;
  }
  cout << endl;
}
