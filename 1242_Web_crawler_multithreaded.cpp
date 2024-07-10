#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_set>
#include <vector>
#include <string>

class HtmlParser {
  public:
      std::vector<std::string> getUrls(std::string url);
};


class Solution {
    std::mutex mut;
    std::condition_variable cond;
    std::unordered_set<std::string> appeared;
    std::queue<std::string> q;

public:
    std::string getHostName(std::string url) {
        size_t pos = url.find("/", 7);
        if (pos == std::string::npos) {
            return url;
        }
        return url.substr(0, pos);
    }

    std::vector<std::string> crawl(std::string startUrl, HtmlParser htmlParser) {
        std::string hostName = getHostName(startUrl);

        int working_t = 0;
        appeared.insert(startUrl);
        q.push(startUrl);

        auto work = [&] {
            while (true) {
                std::string url;
                {
                    std::unique_lock<std::mutex> lock(mut);
                    cond.wait(lock, [&] { return !q.empty() || working_t == 0;});
                    if (q.empty()) {
                        return;
                    }
                    working_t++;
                    url = q.front();
                    q.pop();
                }

                std::vector<std::string> childUrls = htmlParser.getUrls(url);

                {
                    std::lock_guard<std::mutex> lock(mut);
                    for (std::string childUrl : childUrls) {
                        if (getHostName(childUrl) == hostName && appeared.find(childUrl) == appeared.end()) {
                            q.push(childUrl);
                            appeared.insert(childUrl);
                        }
                    }
                    working_t--;
                    cond.notify_all();
                }
            }
        };

        int numThread = std::thread::hardware_concurrency();
        if (numThread == 0)
            numThread = 4;

        std::vector<std::thread> threads;
        for (int i = 0; i < numThread; i++) {
            threads.push_back(std::thread(work));
        }

        for (std::thread& t: threads) {
            t.join();
        }

        std::vector<std::string> result(appeared.begin(), appeared.end());
        return result;
    }
};
