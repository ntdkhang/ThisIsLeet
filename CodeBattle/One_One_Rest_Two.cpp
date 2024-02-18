#include <vector>
using namespace std;
class Solution {
public:

    // NOT DONE YET

    int oneOneRestTwo(vector<int>& nums) {
        // write your code here
        int l = 0, r = nums.size() - 1, m = (l + r) / 2;

        if (nums.size() == 1) {
            return nums.at(0);
        }
        if (nums.at(0) != nums.at(1)) {
            return nums.at(0);
        } else if (nums.at(nums.size() - 1) != nums.at(nums.size() - 2)) {
            return nums.at(nums.size() - 1);
        }

        while (l < r) {
            m = (l + r) / 2;
            // num at begin or end of list?
            if (nums.at(m) != nums.at(m-1) && nums.at(m) != nums.at(m+1)) {
                return nums.at(m);
            } else if (nums.at(m) != nums.at(m+1)) {
                if ((m - l) % 2 == 0) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if ((m - 1 - l) % 2 == 0) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }

            }
        }
        // 1 1 2 3 3 4 4 8 8 9 9 10 10
        //     1 1 3 3 4 4 8 8 10
        return -1;
    }
};
