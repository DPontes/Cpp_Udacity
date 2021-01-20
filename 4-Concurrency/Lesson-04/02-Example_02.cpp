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
    int getID() { return _id; }
  private:
    int _id;
};

class WaitingVehicles
{
  public:
    WaitingVehicles() : _numVehicles(0) {}

    int getNumVehicles()
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        return _numVehicles;
    }

    bool dataIsAvailable()
    {
        std::lock_guard<std::mutex> myLock(_mutex);
        return !_vehicles.empty();
    }

    Vehicle popBack()
    {
        // perform vector modification udner the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // remove last vector element from the queue
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();
        --_numVehicles;

        return v;   // will not be copied due to the Return Value Optimization (RVO) in c++
    }

    void pushBack(Vehicle && v)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // add vector to queue
        std::cout << "  Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(std::move(v));
        ++_numVehicles;
    }

  private:
    std::vector<Vehicle> _vehicles;     // list of all the vehicles waiting to get into the intersection
    std::mutex _mutex;
    int _numVehicles;
};

int main()
{
    // create monitor oject as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for(size_t i = 0; i < 10; ++i)
    {
        // create a new vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::cout << "Collecting results..." << std::endl;
    while(true)
    {
        if(queue->dataIsAvailable())
        {
            Vehicle v = queue->popBack();
            std::cout << "  Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;

            if(queue->getNumVehicles() <=0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                break;
            }
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished : " << queue->getNumVehicles() << " vehicle(s) left in the queue" << std::endl;

    return 0;
}
