#include <stdexcept>
#include <exception>
#include <iostream>

using namespace std;

int main()
{
  exception_ptr e;

  try {
    throw runtime_error("whatever");
  }
  catch(...) {
    e = current_exception();
  }

  if ( e != nullptr ) {

    try {
      rethrow_exception(e);
    }
    catch( const exception& e ) {
      cout << e.what() << endl;
    }
  }
}
