#include <iostream>
#include <chrono>

using namespace std;

int main()
{
  chrono::duration<double, ratio<60>> half_minute(0.5);
  chrono::seconds thirty_secs(30);
  cout << half_minute.count() << endl;
  cout << thirty_secs.count() << endl;

  chrono::seconds s = thirty_secs - chrono::duration_cast<chrono::seconds>(half_minute);
  cout << s.count() << endl;
}
