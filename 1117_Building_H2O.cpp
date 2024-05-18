#include <iostream>
#include <thread>
#include <mutex>

class H2O {
public:
    std::mutex mut;
    std::condition_variable cond;
    int hydro_count;
    H2O() {
        hydro_count = 0;
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return hydro_count < 2;});
        hydro_count++;
        releaseHydrogen();

        cond.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [=] { return hydro_count == 2;});

        hydro_count = 0;
        releaseOxygen();

        cond.notify_all();
    }
};
