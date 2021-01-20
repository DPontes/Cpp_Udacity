#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if(denom == 0)
        throw std::runtime_error("Exception from thread: divided by zero");

    return num / denom;
}

int main() {

    // define values
    double num = 42.0;
    double denom = 0.0;

    std::future<double> ftr = std::async(divideByNumber, num, denom);

    try {
        double result = ftr.get();
        std::cout << "Result is: " << result << std::endl;
    }
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
