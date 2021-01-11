/*
    QUIZ:
    - what is the order in which the various strings are printed out?
    - what will be the value of ID for each output?
*/

#include <iostream>

int main() {
    int id = 0;

    // capture by reference (immutable)
    auto f0 = [&id]() { std::cout << "a) ID in lambda = " << id << std::endl; };

    // capture by value (mutable)
    auto f1 = [id]() mutable {std::cout << "b) ID in lambda = " << ++id << std::endl; };
    f1();   // call the closure and execute the code within the lambda
    std::cout << "c) ID in main = " << id << std::endl;

    // capture by reference (mutable)
    auto f2 = [&id]() mutable {std::cout << "d) ID in lambda = " << ++id << std::endl; };
    f2();
    std::cout << "e) ID in main = " << id << std::endl;

    // pass parameter
    auto f3 = [](const int id) {std::cout << "f) ID in lambda = " << id << std::endl; };
    f3(++id);

    // observe the effect of capturing by reference at an earlier point in time
    f0();

    return 0;
}
