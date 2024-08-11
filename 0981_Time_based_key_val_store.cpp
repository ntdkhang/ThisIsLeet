#include <string>
#include <unordered_map>

class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> map;
    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
        map[key].push_back(std::pair<int, std::string>(timestamp, value));
    }

    std::string get(std::string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }

        std::vector<std::pair<int, std::string>>& vec = map[key];
        std::string val = "";
        int left = 0, right = vec.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (vec[mid].first == timestamp) {
                return vec[mid].second;
            }
            if (vec[mid].first < timestamp) {
                val = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

