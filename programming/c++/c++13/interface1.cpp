#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class IObject
{
public:
  virtual ~IObject() {}
  virtual string GetString() const = 0;
};

class IInt : virtual public IObject
{
public:
  virtual int GetInt() const = 0;
};

class IDouble : virtual public IObject
{
public:
  virtual double GetDouble() const = 0;
};

void ShowInt(const IInt& obj)
{
  cout << "int: " << obj.GetInt() << endl;
}

void ShowDouble(const IDouble& obj)
{
  cout << "double: " << obj.GetDouble() << endl;
}

class Double :
  virtual public IInt,
  virtual public IDouble
{
public:

  Double(double x) : m_x(x) {}
  virtual string GetString() const
  {
    ostringstream ostr;
    ostr << "Double(" << m_x << ')';
    return ostr.str();
  }

  virtual int GetInt() const
  {
    return static_cast<int>(m_x);
  }

  virtual double GetDouble() const
  {
    return m_x;
  }

private:

  const double m_x;
};

ostream& operator<<(ostream& ostr, const IObject& obj)
{
  return ostr << obj.GetString();
}

int main()
{
  Double n = 1.2;

  cout << n << endl;
  ShowInt(n);
  ShowDouble(n);
}
                                           
