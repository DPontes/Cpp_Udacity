/*
    When passing the string variable name to the thread function,
    we need to explicitly mark it as a reference, so the compiler
    will treat it as such. This can be done by using the std::ref function
*/
#include <iostream>
#include <thread>
#include <string>

void printName(std::string &name, int waitTime) {
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from thread)";
    std::cout << name << std::endl;
}

int main() {
    std::string name("My thread");

    // starting thread
    // the thread function signature is modified to take a non-const
    // reference to the string
    std::thread t(printName, std::ref(name), 50);

    // wait for thread before returning
    t.join();

    name += " (from main)";
    std::cout << name << std::endl;

    return 0;
}
