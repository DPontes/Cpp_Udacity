#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Finished work in thread" << std::endl;
}

int main() {
    // create thread
    std::thread t(threadFunction);

    // detach thread and continue with main
    t.detach();

    // simulate some work in main
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main" << std::endl;

    return 0;
}
