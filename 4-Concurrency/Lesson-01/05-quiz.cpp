#include <iostream>
#include <thread>

class Vehicle {
  public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void setName(std::string name) { _name = name; }
    void printID() { std::cout << "Vehicle ID: " << _id << std::endl; }
    void printName() { std::cout << "Vehicle Name: " << _name << std::endl; }

  private:
    int _id;
    std::string _name;
};

int main() {
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t1(&Vehicle::addID, v, 1);
    std::thread t2(&Vehicle::setName, v, "Bob");

    t1.join();
    t2.join();

    v->printID();
    v->printName();

    return 0;
}
