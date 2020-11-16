 /*
    - Define the abstract class Shape
    - Define public virtual functions Area() and Perimeter()
    - Append the declarations with = 0 to specify pure virtual functions
    - Define Rectangle to inherit publicly from Shape
    - Declare public constructor
    - Override virtual base class functions Area() and Perimeter()
    - Declare private attributes width and height
    - Define Circle to inherit from Shape
    - Declare public constructor
    - Override virtual base class functions Area() and Perimeter()
    - Declare private member variable radius
 */
#include <cmath>
#include <cassert>

class Shape {
  public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
  public:
    Rectangle(int height, int width) : height(height), width(width) {}

    double Area() const { return height * width; }
    double Perimeter() const { return 2 * height + 2 * width; }

  private:
    int height;
    int width;
};

class Circle : public Shape {
  public:
    Circle(double radius) : radius(radius) {}
    double Perimeter() const { return M_PI * 2 * radius; }
    double Area() const { return M_PI * pow(radius, 2); }

  private:
    double radius;
};

int main() {
    double epsilon = 0.1;   // Useful for floating point equality

    Circle circle(12.31);
    assert( abs(circle.Perimeter() - 77.35) < epsilon );
    assert( abs(circle.Area() - 476.06) < epsilon );

    Rectangle rectangle(10, 6);
    assert( rectangle.Perimeter() == 32 );
    assert( rectangle.Area() == 60 );

}
