#include <condition_variable>
#include <mutex>

class TrafficLight {
    int turnGreenId, crossId;
    std::mutex turn_mut, cross_mut;
    std::condition_variable cond;

public:
    TrafficLight() {
        turnGreenId = 1;
        crossId = 1;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        std::function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        std::function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        std::unique_lock<std::mutex> lock(turn_mut);
        std::condition_variable cond;


        if (turnGreenId != roadId) {
            turnGreen();
            turnGreenId = roadId;
        }

        crossCar();

    }
};
