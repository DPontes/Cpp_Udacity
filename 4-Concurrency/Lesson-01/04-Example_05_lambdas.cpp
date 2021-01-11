/*
    The function object is first created and then used to pass
    the parameter id later in the code
*/
#include <iostream>

int main() {
    int id = 0;

    auto f = [](const int id) { std::cout << "ID = " << id << std::endl; };     // ID is passed as parameter

    // execute lambda function and pass ID as a parameter
    f(id);

    return 0;
}
