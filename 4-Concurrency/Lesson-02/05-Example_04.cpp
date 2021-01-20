#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
  public:
    // Default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name"))
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    // Initializing constructor
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name))
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // move constructor
    Vehicle(Vehicle && src) : _name(std::move(src._name))
    {
        _id = src.getID();
        src.setID(0);

        std::cout << "Vehicle #" << _id << " Move constructor called" << std::endl;
    }

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }
    void setName(std::string name) { *_name = name; }
    std::string getName() { return *_name; }

  private:
    int _id;
    std::unique_ptr<std::string> _name;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    // launch a thread that modifies the vehicle name
    std::future<void> ftr = std::async([](Vehicle v) {
        v.setName("Vehicle 2");
    }, std::move(v0));

    v0.setName("Vehicle 3");

    ftr.wait();

   // std::cout << v0.getName() << std::endl;       // This will now create an exception

    return 0;
}
