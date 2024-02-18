#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l<=r) {
            mid = (l + r) / 2;
            if (nums.at(mid) < target) {
                l = mid + 1;
            } else if (nums.at(mid) > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        // [-1,0,3,5,9,12]
        return -1;
    }
};
