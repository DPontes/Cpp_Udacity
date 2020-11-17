// Declare a generic templatized function Max()
#include <cassert>

template <typename T> T Max(T a, T b) { return a > b ? a : b; }

int main() {
    assert( Max(10 ,50) == 50 );
    assert( Max(5.7 ,1.4353456) == 5.7 );

    return 0;
}
