// Create a generic function Product that multiplies two parameters
#include <cassert>

template <typename T> T Product(T a, T b) { return a * b; }

int main() {
    assert( Product<int> (10, 2) == 20 );

    return 0;
}
