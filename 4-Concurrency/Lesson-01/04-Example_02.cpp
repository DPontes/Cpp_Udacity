#include <iostream>
#include <thread>

class Vehicle {
  public:
    void operator()() {
        std::cout << "Vehicle object has been created" << std::endl;
    }
};

int main() {
    /*
    using

    std::thread t(Vehicle());

    would through a compiler warning plus an error due to the syntatic ambiguity
    of the declaration, as it can be interpreted as:

    1. a definition of variable 't' of class 'std::thread', initialized with an
    anonymous instance of class 'Vehicle'
    2. a function declaration for a function 't' that returns an object of type
    'std::thread' and has a single (unnamed) parameter that is a pointer to a
    function returning an object of type 'Vehicle'

    The C++ standard requires it to be interpreted as the 2nd - hence the warning

    There are however 3 ways of forcing the compiler to consider it as the 1st case,
    which would create the desired thread object:

    1. add an extra pair of parentheses
    2. Use copy initialization
    3. Use uniform intialization with braces
    */

    std::thread t1( (Vehicle()) );              // Option 1
    std::thread t2 = std::thread( Vehicle() );  // Option 2
    std::thread t3{ Vehicle() };                // Option 3

    // Do something in main
    std::cout << "Finished work in main" << std::endl;

    // wait for thread to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
