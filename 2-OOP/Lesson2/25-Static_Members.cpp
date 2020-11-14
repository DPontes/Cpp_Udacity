/*
    Update class Sphere to move the volume calculation into a static function
*/
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
  public:
    static float Volume(int radius) {
        return M_PI * 4/3 * pow(radius, 3);
    }
};


int main() {
    assert( abs(Sphere::Volume(5) - 523.6) < 1);
}
