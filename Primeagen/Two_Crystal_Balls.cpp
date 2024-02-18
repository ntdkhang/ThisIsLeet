#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int two_crystal_balls(vector<bool> breaks) {
    const int sqrt_floor = sqrt(breaks.size());
    int floor = sqrt_floor;
    while (floor < breaks.size()) {
        if (breaks[floor]) {
            break;
        } else {
            floor += sqrt_floor;
        }
    }

    // 1st crystal ball broken

    floor -= sqrt_floor;

    for (; !breaks[floor] && floor < breaks.size(); floor++) {}

    return floor;
}

int main() {
    cout << "Hello World" << endl;
    return 0;
}
