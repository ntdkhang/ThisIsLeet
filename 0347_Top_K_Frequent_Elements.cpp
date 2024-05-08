#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> appearance;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            appearance[*iter]++;
        }
        vector<pair<int, int>> sorted(appearance.begin(), appearance.end());
        sort(sorted.begin(), sorted.end(), cmp);
        int count = 0;
        for (auto iter = sorted.begin(); iter != sorted.end() && count < k; iter++) {
            result.push_back(iter->first);
            count++;
        }
        return result;
    }
};
