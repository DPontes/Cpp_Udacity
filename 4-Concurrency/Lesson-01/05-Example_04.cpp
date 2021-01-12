#include <iostream>
#include <thread>
#include <string>

class Vehicle {
  public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID() { std::cout << "Vehicle ID: " << _id << std::endl; }

  private:
    int _id;
};

int main() {
    // create thread
    Vehicle v1, v2;
    std::thread t1(&Vehicle::addID, v1, 1);     // call member function on object v
    std::thread t2(&Vehicle::addID, &v2, 2);     // call member function on object v

    // wait for threads to finish
    t1.join();
    t2.join();

    // print vehicle id
    v1.printID();
    v2.printID();

    return 0;
}
