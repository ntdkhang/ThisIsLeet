#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int count = 1, maxCount = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) {
                count++;
            } else if (nums[i] - nums[i-1] > 1) {
                maxCount = max(count, maxCount);
                count = 1;
            }
        }
        maxCount = max(count, maxCount);
        return maxCount;
    }
};

