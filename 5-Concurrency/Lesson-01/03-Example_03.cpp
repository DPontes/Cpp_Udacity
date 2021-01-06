#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finished work in thread!" << std::endl;
}

int main () {
    // Create thread
    std::thread t(threadFunction);

    // simulate work in main
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main" << std::endl;

    // Wait for thread to finish
    t.join();

    return 0;
}
