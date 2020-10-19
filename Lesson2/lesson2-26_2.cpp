// Enums with a switch
#include <iostream>

using std::cout;
using std::endl;

int main() {
    enum class Direction {kUp, kDown, kLeft, kRight};

    Direction a = Direction::kUp;

    switch(a) {
        case Direction::kUp : cout << "Going Up" << endl;
        break;

        case Direction::kDown : cout << "Going Down" << endl;
        break;

        case Direction::kLeft : cout << "Going Left" << endl;
        break;

        case Direction::kRight : cout << "Going Right" << endl;
        break;

        default: break;
    }

    return 0;
}
