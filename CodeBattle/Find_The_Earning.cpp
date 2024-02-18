#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        //write your code here

        sort(rides.begin(), rides.end(), [](const vector<int>& x, const vector<int>& y) {
                return x.at(0) < y.at(0);
                });

        vector<long long> dp(n + 1, 0);

        // dp[i] is the max amount of earning you can get arriving at i
        int last_check = 0;
        long long res = 0;
        for (auto ride: rides) {
            int begin = ride.at(0);
            int end = ride.at(1);
            int tip = ride.at(2);

            for (int i = last_check; i < begin; i++) {
                dp[begin] = max(dp[i], dp[begin]);
            }
            last_check = begin;

            dp[end] = max(dp[end], dp[begin] + (end - begin + tip));
            res = max(res, dp[end]);
        }

        return res;
    }
};


