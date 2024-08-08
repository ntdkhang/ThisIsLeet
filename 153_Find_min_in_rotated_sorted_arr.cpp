#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid;
        int min = nums[0];
        while (left <= right) {
            mid = (left + right) / 2;
            min = std::min(min, nums[mid]);
            if (nums[mid] > nums.back()) { // the drop happen after you
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        return min;
    }
};

