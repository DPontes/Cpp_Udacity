// compile with: g++ -pthread 02-example_02.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>

class Vehicle
{
  public:
    Vehicle(int id) : _id(id) {}

  private:
    int _id;
};

class WaitingVehicles
{
  public:
    WaitingVehicles() {}

    // getters / setters
    void printSize()
    {
      _mutex.lock();
      std::cout << "#vehicles: " << _vehicles.size() << std::endl;
      _mutex.unlock();
    }

    void pushBack(Vehicle &&v)
    {
      _mutex.lock();
      _vehicles.emplace_back(std::move(v));
      _mutex.unlock();
    }

  private:
    std::mutex _mutex;
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
};

int main()
{
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  std::vector<std::future<void>> futures;

  for(int i = 0; i < 1000; ++i)
  {
    Vehicle v(i);
    futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }

  std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
    ftr.wait();
  });

  queue->printSize();

  return 0;
}
