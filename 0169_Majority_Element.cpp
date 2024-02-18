// Given an array nums of size n, return the majority element

#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorityNum = 0;
        for (int num : nums) {
            if (count == 0) {
                majorityNum = num;
            }
            count += majorityNum == num ? 1 : -1;
        }
        return majorityNum;

        /* 
        unordered_map<int, int> numCount;
        for (int num : nums) {
            if (numCount.count(num) > 0) {
                numCount[num]++;
            } else {
                numCount[num] = 1;
            }
        }
        for (auto& it: numCount) {
            if (it.second >= (nums.size() / 2)) {
                return it.first;
            }
        }
        */
    }
};
