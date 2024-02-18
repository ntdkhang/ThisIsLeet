#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& nums,int m) {
        // write your code here
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        for (int i = 0; i <= nums.size() - m; i++) {
            min_diff = min(min_diff, nums.at(i + m - 1) - nums.at(i));
        }
        return min_diff;
    }
};
