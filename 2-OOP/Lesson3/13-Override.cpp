/*
    - Define class ParticleModel, including its state and Move() function.
    - Extend class BicycleModel from class ParticleModel.
    - Override the Move() function within class BicycleModel.
    - Specify BicycleModel::Move() as override.
    - Pass the tests in main() by verifying that the two Move() functions override each other in different scenarios.
*/
#include <cassert>
#include <cmath>

class VehicleModel {
  public:
    virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public VehicleModel {
  public:
    void Move(double v, double phi) override {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }

    double x = 0;
    double y = 0;
    double theta = 0;
};

class BicycleModel : public ParticleModel {
  public:
    void Move(double v, double phi) override {
        theta += v / L * tan(phi);
        x += v * cos(theta);
        y += v * sin(theta);
    }
    double L = 1;
};


int main() {
    ParticleModel particle;
    BicycleModel bicycle;

    particle.Move(10, M_PI / 9);
    bicycle.Move(10, M_PI / 9);

    assert( particle.x != bicycle.x);
    assert( particle.y != bicycle.y);
    assert( particle.theta != bicycle.theta);
}
