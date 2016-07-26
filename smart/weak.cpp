#include <iostream>
#include <memory>

using namespace std;

int main()
{
  weak_ptr<int> w;

  {
    shared_ptr<int> s{ new int{11} };

    {
      shared_ptr<int> t = s;
      cout << *t << endl;
    }

    w = s;
    cout << boolalpha << w.expired() << endl;
    cout << *w.lock() << endl;
  }

  cout << boolalpha << w.expired() << endl;
}
