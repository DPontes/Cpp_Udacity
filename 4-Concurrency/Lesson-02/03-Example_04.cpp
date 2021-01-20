#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <vector>
#include <chrono>

void workerFunction(int n) {
    // print system id of the worker thread
    std::cout << "Worker thread id: " << std::this_thread::get_id() << std::endl;

    // perform work
    for (int i = 0; i < n; i++) {
        sqrt(12345.6789);
    }
}

int main() {
    // print system id of the main thread
    std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;

    // start time measurement
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    // launch various tasks
    std::vector<std::future<void>> futures;
    int nLoops = 10, nThreads = 5;
    for (int i = 0; i < nThreads; i++) {
        // try changing std::launch::deferred to std::launch::async and compare the results
        futures.emplace_back(std::async(std::launch::deferred, workerFunction, nLoops));
    }

    // wait for tasks to complete
    for (const std::future<void> &ftr : futures) {
        ftr.wait();
    }

    // stop the measurement and print execution time
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution finished after " << duration << " microseconds." << std::endl;

    return 0;
}
