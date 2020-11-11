// Encapsulation 3
#include <string>
#include <iostream>
#include <cstring>

class Car {
  private:
    std::string brand;

  public:
    std::string GetBrand() const;
    void SetBrand(char*);
};

void Car::SetBrand(char* brand) {
    Car::brand = brand;
}

std::string Car::GetBrand() const {
    return brand;
}

int main() {
    Car car;
    char brand[] = "Peugeot";

    car.SetBrand(brand);
    std::cout << car.GetBrand() << std::endl;

    return 0;
}
