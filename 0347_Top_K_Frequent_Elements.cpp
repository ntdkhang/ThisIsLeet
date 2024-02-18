#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res{};
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }

        vector<pair<int, int>> a;
        for (auto ele: map){
            a.push_back(pair(ele.first, ele.second));
        }

        sort(a.begin(), a.end(), [](auto x, auto y) {
                return x.second > y.second;
                });

        for (int i = 0 ; i < k; i++) {
            res.push_back(a[i].first);
        }
        return res;
    }
};
