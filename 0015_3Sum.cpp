#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret;
        // vector<vector<int>> ret;
        unordered_map<int, int> appeared;
        sort(nums.begin(), nums.end());

        for (int num : nums) {
            appeared[num] += 1;
        }

        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int target = - (nums[i] + nums[j]);
                --appeared[nums[i]];
                --appeared[nums[j]];
                if (appeared[target] > 0) {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(target);
                    sort(triplet.begin(), triplet.end());
                    ret.insert(triplet);
                }
                ++appeared[nums[i]];
                ++appeared[nums[j]];
            }
        }

        vector<vector<int>> output;
        for (auto triplet : ret) {
            output.push_back(triplet);
        }
        return output;
    }
};
