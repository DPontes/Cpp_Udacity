/*
    A heap-allocated object and a reference-counted pointer such as
    std::shared_ptr<Vehicle> are used to ensure that the object lives 
    as long as it takes the thread to finish its work.
*/
#include <iostream>
#include <thread>

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
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t(&Vehicle::addID, v, 1);

    t.join();

    v->printID();

    return 0;
}
