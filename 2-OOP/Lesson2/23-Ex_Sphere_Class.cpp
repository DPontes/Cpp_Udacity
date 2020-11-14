// Create a class which represents a sphere
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
  public:
    Sphere(int radius) : radius_(radius),
                         volume_(M_PI * 4/3 * pow(radius_, 3)) {
        if (radius <= 0) throw std::invalid_argument("Radius must be positive");
    }
    int Radius() const { return radius_; }
    double Volume() const { return volume_; }


  private:
    double volume_;
    int radius_;
};


int main() {
    Sphere sphere(5);
    assert( sphere.Radius() == 5);
    assert( abs(sphere.Volume() - 523.6 ) < 1);
}
