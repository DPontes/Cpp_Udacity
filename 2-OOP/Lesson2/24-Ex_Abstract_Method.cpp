/*
    Update class Sphere so that it becomes possible to change the radius of
    a sphere after it's been initialized
*/
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
  public:
    Sphere(int radius) : radius_{ radius },
                         volume_{ CalcVolume(radius_) } {
        ValidateRadius(radius_);
    }

    int Radius()    const { return radius_; }
    double Volume() const { return volume_; }

    void Radius(int radius) {
        ValidateRadius(radius);
        radius_ = radius;
        volume_ = CalcVolume(radius_);
    }

  private:
    double volume_;
    int radius_;

    double CalcVolume(int radius_) const {
        return M_PI * 4.0/3.0 * pow(radius_, 3);
    }

    void ValidateRadius(int valid_radius) const {
        if ( valid_radius <= 0 ) {
            throw std::invalid_argument("radius must be positive");
        }
    }
};


int main() {
    Sphere sphere(5);
    assert( sphere.Radius() == 5);
    assert( abs(sphere.Volume() - 523.6 ) < 1);

    sphere.Radius(3);
    assert( sphere.Radius() == 3);
    assert( abs(sphere.Volume() - 113.1 ) < 1);

    bool caught {false};
    try {
        sphere.Radius(-1);
    } catch (...) {
        caught = true;
    }
    assert(caught);
}
