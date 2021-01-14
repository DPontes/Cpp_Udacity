#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> && prms, double input) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    double output = sqrt(input);
    prms.set_value(output);
}

int main() {
    //define input data
    double input = 42.0;

    // create promise and future
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    // start thread and pass promise as argument
    std::thread t(computeSqrt, std::move(prms), input);

    // wait for results to be available
    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if ( status == std::future_status::ready) {      // result is ready
        std::cout << "Result = " << ftr.get() << std::endl;
    } else if (status == std::future_status::timeout || status == std::future_status::deferred) {
        std::cout << "Result unavailable" << std::endl;
    }

    t.join();

    return 0;
}
