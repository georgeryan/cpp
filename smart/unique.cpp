#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct c {
  c( int _i ) : i(_i) {}
  ~c() { cout << i << endl; }

  int i;
};

int main()
{
  {
    vector<unique_ptr<c>> v;
    v.push_back( unique_ptr<c>( new c(1)) );
    v.push_back( unique_ptr<c>( new c(11)) );
  }

  unique_ptr<int> u1( new int(4) );
  unique_ptr<int> u2( std::move(u1) );

  cout << boolalpha << ( u1 == nullptr ) << endl;

  unique_ptr<string[]> s(new string[10]);
  s[0] = "George";
  cout << s[0] << endl;
}
