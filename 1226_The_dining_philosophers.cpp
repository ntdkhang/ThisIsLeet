#include <mutex>
#include <condition_variable>
#include <vector>


class DiningPhilosophers {
    std::mutex mut;
    std::condition_variable cond;
    std::vector<bool> fork;
public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            fork.push_back(true);
        }

    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {

        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, [&] { return (fork[philosopher] && fork[(philosopher + 1) % 5]); });

        pickLeftFork();
        fork[philosopher] = false;

        pickRightFork();
        fork[(philosopher + 1) % 5] = false;

        eat();

        putLeftFork();
        fork[philosopher] = true;

        putRightFork();
        fork[(philosopher + 1) % 5] = true;
        cond.notify_all();
    }
};
