#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/array.hpp>
#include <vector>
using namespace std;

// class Select
// {
// public:

//   virtual void test() = 0;

// private:

//   const char* const nowstate;
// };

// class A1 : virtual public Select
// {
// public:

//   void Attack(); // attack 
//   void Magic();  // magic
//   void Protect();// protecte

//   static const char* const a1menu[];
// };

// const char* const A1::a1menu[] =
// {
//   "Attack", "Magic", "Protect"
// };

// class Attack : virtual public Select
// {
// public:

//   void Fire();
//   void Ice();
//   void Wind();
  
//   static const char* const a2menu[];
// };

// const char* const A2::a2menu[] =
// {
//   "Fire", "Ice", "Wind"
// };

// class Rpg
// {
// public:

//   int attack();

// };

// class MenuStateMachine
// {
// public:
//   void Change();

// private:
//   vector<Select* > gameState;
// };

// void MenuStateMachine()
// {
// };

int main()
{
  // vector<Select* > gameState;
  boost::array<int, 5> ar = {3, 1, 44, 3, 34};
  boost::array<double, 5> ab = {5.3, 4.5, 3.2, 2, 1};
  for(int i = 0; i < ar.size(); i++)
  {
    cout << ar[i] << endl;
  }
  ar = ab;
  for(int i = 0; i < ar.size(); i++)
  {
    cout << ar[i] << endl;
  }
}
