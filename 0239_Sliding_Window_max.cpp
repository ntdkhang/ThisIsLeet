#include <deque>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> maxIndex;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // check if front exist && already pass the window
            while (!maxIndex.empty() && maxIndex.front() < i - k + 1) {
                maxIndex.pop_front();
            }
            while (!maxIndex.empty() && nums[i] > nums[maxIndex.back()]) {
                maxIndex.pop_back();
            }
            maxIndex.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[maxIndex.front()]);
            }
        }

        return result;
    }
};
