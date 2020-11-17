// declare a generic, templatized average function
#include <cassert>

template <typename T> T average(T a, T b) { return (a + b) / 2; }

int main() {
    // average is called without referring the type of the variables
    assert( average(2.0, 5.0) == 3.5 );
}
