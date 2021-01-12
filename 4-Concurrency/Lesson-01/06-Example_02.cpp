#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

int main() {
    // create threads
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 10; ++i) {

        // create a new thread from a lambda
        threads.emplace_back([i]() {
            // wait for a certain amount of time
            std::this_thread::sleep_for(std::chrono::milliseconds(10 + 10 * i));

            // perform work
            std::cout << "Hello from worker thread #" << i << std::endl;
        });
    }

    // do something in main
    std::cout << "Hello from main thread" << std::endl;

    for (auto& t : threads)
        t.join();

    return 0;
}
