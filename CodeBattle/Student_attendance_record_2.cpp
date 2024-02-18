#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int checkRecord(int n) {
        // write your code here

        // dp[day][late][absent] = how many valid combination after day days of going to class, with late days continuously going late including today, and absent days till now
        // dp[5][2][1] = at day 5, how many valid combination when you go 2 days late including this class and 1 day absent.
        // late = {0, 1, 2}
        // absent = {0, 1}

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[1][0][0] = 1;
        dp[1][1][0] = 1;
        dp[1][0][1] = 1;

        for (int i = 2; i <= n; i++) {
            // If you are absent today -> you can only use results from days before that have no absent, and reset the late to 0
            // -> add the result of today to the 2 results of going late before today.
            for (int late = 0; late <= 2; late++) {
                dp[i][0][1] = (dp[i][0][1] + dp[i-1][late][0]) % MOD;
            }

            // if you are late today -> you can only use results from days before with 0 or 1 late days
            // -> iterate over 2 late combination & 2 absents combination
            for (int absent = 0; absent <= 1; absent++) {
                for (int late = 0; late <= 1; late++) {
                    dp[i][late+1][absent] = (dp[i][late+1][absent] + dp[i-1][late][absent]) % MOD;
                }
            }

            // if you are present today -> you can use any results from days before
            for (int absent = 0; absent <= 1; absent++) {
                for (int late = 0; late <= 2; late++) {
                    dp[i][0][absent] = (dp[i][0][absent] + dp[i-1][late][absent]) % MOD;
                }
            }
        }
        int res = 0;
        for (int absent = 0; absent <= 1; absent++) {
            for (int late = 0; late <= 2; late++) {
                res = (res + dp[n][late][absent]) % MOD;
            }
        }
        return res;
    }
};


int main() {
    Solution sol{};
    cout << sol.checkRecord(4) << endl;
}
