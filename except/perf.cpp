#include <iostream>
#include <stdexcept>

using namespace std;

void foo() throw (runtime_error) 
{
  throw runtime_error("");
}

int main()
{
  foo();
}
