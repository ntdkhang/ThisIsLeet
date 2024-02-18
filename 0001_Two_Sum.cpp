#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int num_to_find = target - nums.at(i);
            if (auto search = map.find(num_to_find); search != map.end()) {
                res.push_back(search->second);
                res.push_back(i);
                return res;
            }
            map[nums.at(i)] = i;
        }
        cout << "ERROR: NO SOLUTION FOUND" << endl;
        return res;




        // unordered_map<int, vector<int>> map;

        // for (int i = 0; i < nums.size(); i++) {
        //     map[nums[i]].push_back(i);
        // }
        //
        // for (int i = 0; i < nums.size(); i++) {
        //     int num_to_find = target - nums.at(i);
        //
        //     if (map.count(num_to_find) != 0) {
        //         if (num_to_find == nums.at(i)) {
        //             if (map[num_to_find].size() == 2) {
        //                 res = map[num_to_find];
        //                 return res;
        //             }
        //         } else if (map[num_to_find].size() > 0) {
        //             res.push_back(i);
        //             res.push_back(map[num_to_find].at(0));
        //             return res;
        //         }
        //     }
        // }
        // cout << "ERROR: NO SOLUTION FOUND" << endl;
        // return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums {-18,12,3,0};
    cout << sol.twoSum(nums, -6).at(0) << sol.twoSum(nums, -6).at(1);
    return 0;
}
