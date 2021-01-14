#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

void divideByNumber(std::promise<double> && prms, double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    try {
        if(denom == 0)
            throw std::runtime_error("Exception from thread: divided by zero");
        else
            prms.set_value( num / denom);
    }
    catch(...) {
        prms.set_exception(std::current_exception());
    }
}

int main() {

    // define values
    double num = 42.0;
    double denom = 0.0;

    // create promise and future
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    // start thread and pass promise as an argument
    std::thread t(divideByNumber, std::move(prms), num, denom);

    try {
        double result = ftr.get();
        std::cout << "Result is: " << result << std::endl;
    }
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    t.join();

    return 0;
}
