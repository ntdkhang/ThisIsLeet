#include <mutex>
#include <condition_variable>
#include <vector>

class my_semaphore {
    std::mutex mut;
    std::condition_variable cond;
    int value;
public:
    my_semaphore() {
        value = 0;
    }

    my_semaphore(int i) : value(i) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [this] { return value > 0; });
        value--;
    }

    void signal() {
        std::lock_guard<std::mutex> lock(mut);
        value++;
        if (value == 1) {
            cond.notify_all();
        }
    }
};


class DiningPhilosophers {
    my_semaphore sems[5] {my_semaphore{1},my_semaphore{1},my_semaphore{1},my_semaphore{1},my_semaphore{1}};
    std::mutex mut;
    std::condition_variable cond;

public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {

        {
            std::lock_guard<std::mutex> lock(mut);
            sems[(philosopher + 1) % 5].wait();
            sems[philosopher].wait();
        }
        pickLeftFork();
        pickRightFork();
        eat();

        putLeftFork();
        sems[(philosopher + 1) % 5].signal();

        putRightFork();
        sems[philosopher].signal();
    }
};
