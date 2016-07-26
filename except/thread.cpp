#include <iostream>
#include <thread>
#include <exception>
#include <stdexcept>

using namespace std;

static exception_ptr e = nullptr;

void foo()
{
  try {
    this_thread::sleep_for( chrono::seconds(1) );
    throw runtime_error("thread exception");
  }
  catch (...) {
    e = current_exception();    
  }
}

int main()
{
  thread m(foo);
  m.join();

  if ( e ) {
    try {
      rethrow_exception(e);
    }
    catch( const exception& e ) {
      cout << e.what() << endl; 
    }
  }
}
