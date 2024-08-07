#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        int midIdx;

        while (left <= right) {
            midIdx = (left + right) / 2;

            if (nums[midIdx] == target) {
                return midIdx;
            } else if (nums[midIdx] > target) {
                right = midIdx - 1;
            } else {
                left = midIdx + 1;
            }
        }

        return -1;
    }
};

