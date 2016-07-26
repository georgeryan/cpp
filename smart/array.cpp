#include <iostream>
#include <memory>

using namespace std;

int main()
{
  shared_ptr<int> s{ new int[11], default_delete<int[]>() };
  shared_ptr<int> s2{ new int[11], [](int* p){ delete [] p; }};
}
