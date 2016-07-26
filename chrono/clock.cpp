#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
  chrono::system_clock::time_point now = chrono::system_clock::now();
  time_t t = chrono::system_clock::to_time_t(now);
  cout << ctime(&t) << endl;
}

