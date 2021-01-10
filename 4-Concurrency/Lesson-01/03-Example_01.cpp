#include <iostream>
#include <thread>

int main() {
    std::cout << "Hello concurrent world of main! Thread id = " << std::this_thread::get_id() << std::endl;

    return 0;
}
