/*
   -  Declare a class Rectangle.
   -  Define a class Square.
   -  Add class Rectangle as a friend of the class Square.
   -  Add a private attribute side to class Square.
   -  Create a public constructor in class Square that initializes the side attribute.
   -  Add private members width and height to class Rectangle.
   -  Add a Rectangle() constructor that takes a Square as an argument.
   -  Add an Area() function to class Rectangle.
*/
#include <cassert>

class Rectangle {
  public:
    Rectangle (const Square& a) {}
    int Area() const;
  private:
    int width  {0};
    int height {0};
};

class Square {
  public:
    Square(int s) : side(s) {}
  private:
    int side;
    friend class Rectangle;
};

// Define a Rectangle constructor that takes a square
Rectangle::Rectangle ( const Square& a) : width(a.side), height(a.side) {}

int Rectangle::Area() const {
    return width * height;
}

int main() {
    Square square{4};
    Rectangle rectangle{square};
    assert( rectangle.Area() == 16 );
}
