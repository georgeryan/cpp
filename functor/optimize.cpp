#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool foo( int i )
{
  return i > 5 && i < 10;
}

struct bar {
  bool operator()( int i )
  {
    return i > 5 && i < 10;
  }
};

int main()
{
  list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 22 };
  //auto pos = find_if( l.begin(), l.end(), foo );
  //auto pos = find_if(l.begin(), l.end(), bar());
  auto post = find_if(l.begin(), l.end(), [](int i) { return i > 5 && i < 10; });
}
