#include <iostream>
#include <string>

using namespace std;

string f() { return "Hello"; }

int main()
{
  string var{"George"};

  string& r1 {var};  // lvalue reference, bind r1 to var (an lvalue)
  // string& r2 {f()};  // lvalue reference error, 'cause f() is a rvalue
  // string& r3 {"Ryan"}; // lvalue reference error, can't bind to temporary

  string&& rr1 {f()}; // rvalue reference ok, f() returns a rvalue (e temporary)
  //string&& rr2 {var}; // rvalue reference error, var is an lvalue
  string&& rr3 {"William"}; // rvalue reference ok, 'cause value is a temporary (rvalue)

  string&& rr4 {move(var)}; // rvalue reference ok, cause move change lvalue to rvalue
}
