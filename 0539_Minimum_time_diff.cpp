#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    int findDifference(std::string time1, std::string time2) {
        int time1_in_min = std::stoi(time1.substr(0,2)) * 60 + std::stoi(time1.substr(3, 2));
        int time2_in_min = std::stoi(time2.substr(0,2)) * 60 + std::stoi(time2.substr(3, 2));
        int diff = std::abs(time1_in_min - time2_in_min);

        diff = std::min(diff, 1440 - diff);

        return diff;
    }

    int findMinDifference(std::vector<std::string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());

        int minDiff = 1440;
        for (int i = 0; i < timePoints.size() - 1; i++) {
            minDiff = std::min(minDiff, findDifference(timePoints[i], timePoints[i+1]));
        }
        minDiff = std::min(minDiff, findDifference(timePoints[0], timePoints[timePoints.size() - 1]));

        return minDiff;
    }
};
