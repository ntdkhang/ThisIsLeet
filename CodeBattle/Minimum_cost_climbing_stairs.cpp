#include <vector>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // write your code here
        vector<int> dp(cost.size() + 1, 0);

        // dp.at(0) = cost.at(0);
        // dp.at(1) = cost.at(1);
        for (int i = 2; i <= cost.size(); i++) {
            dp.at(i) = min(dp.at(i-1) + cost.at(i-1), dp.at(i-2) + cost.at(i-2));
        }
        return dp.at(dp.size()-1);
    }
};
