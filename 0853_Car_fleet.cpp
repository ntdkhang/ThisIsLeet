// @leet start
#include <vector>
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> zipped; // pair<position, speed>
        for (int i = 0; i < position.size(); i++) {
            zipped.push_back(std::pair(position[i], speed[i]));
        }
        std::sort(zipped.begin(), zipped.end(), [](const std::pair<int, int>&a, const std::pair<int, int>&b){
                return a.first > b.first;
                });


        float cur_fleet_time = 0;
        int fleets_count = 0;

        for (int i = 0; i < position.size(); i++) {
            float time = (float(target) - zipped[i].first) / zipped[i].second;
            if (time < cur_fleet_time) {
                // do nothing?
            }

            if (time > cur_fleet_time) {
                cur_fleet_time = time;
                fleets_count++;
            }
        }

        return fleets_count;
    }
};
// @leet

