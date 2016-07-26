#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <algorithm>
#include <pthread.h>

using namespace std;

int main()
{
  constexpr unsigned int num_threads = 4;
  //const unsigned int num_cpus = thread::hardware_concurrency();
  //cout << "have " << num_cpus << " cpus\n";
  
  mutex m;

  vector<thread> threads(num_threads);
  for ( unsigned int i = 0; i < num_threads; ++i ) {
    threads[i] = thread( [&m, i] {
      this_thread::sleep_for(chrono::milliseconds(20));
      while (1) {
        {
          lock_guard<mutex> l(m);
          cout << "thread #" << i << " on cpu << " << sched_getcpu() << "\n";
        }

        this_thread::sleep_for(chrono::milliseconds(900));
      }
    });

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(i, &cpuset);
    pthread_setaffinity_np(threads[i].native_handle(), sizeof(cpu_set_t), &cpuset);
  }

  for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
}
