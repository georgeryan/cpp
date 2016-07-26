#include <iostream>
#include <ratio>

using namespace std;

int main()
{
  cout << ratio<5,3>::num << "/" << ratio<5,3>::den << endl;
  cout << ratio<25,15>::num << "/" << ratio<25,15>::den << endl;
  cout << ratio<42,42>::num << "/" << ratio<42,42>::den << endl;

  typedef ratio_multiply<ratio<4,5>, ratio<6,2>> r;
  cout << r::num << "/" << r::den << endl;
}
