#include <iostream>
#include <vector>
using namespace std;

template <template <typename, typename> class TEMP>
class A
{
public:
  void Run()
  {
    m_v.push_back(1);
    m_v.push_back(3);
    m_v.push_back(5);

    for(vector<int>::iterator first = m_v.begin(); first != m_v.end(); ++first)
    {
      cout << *first << ' ';
    }
    cout << endl;
  }

private:
  TEMP<int, allocator<int> > m_v;
};

int main()
{
  A<vector> a;
  a.Run();
}
