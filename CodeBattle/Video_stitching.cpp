#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // Write your code here
        sort(clips.begin(), clips.end(), [](const vector<int>& x, const vector<int>& y) {
                return x.at(0) < y.at(0);
                });

        vector<int> dp(T + 1, 0); // dp[i] = the least amount of clips needed to fill all the way from 0 to i
        int last_stitch = -1;
        vector<int> clip;

        for (int i = 0; i < clips.size(); i++) {
            clip = clips.at(i);
            int begin = min(clip.at(0), T);
            int end = min(clip.at(1), T);

            if (begin == 0) {
                dp[end] = 1;
            } else if (dp[end] == 0 && dp[begin] != 0) {
                dp[end] = dp[begin] + 1;
            } else {
                // do nothing?
                // dp[end] = min(dp[end], dp[begin - 1] + 1);
            }
            for (int j = end; j > last_stitch; j--) {
                dp[j] = dp[end];
            }
            last_stitch = max(last_stitch, end);

        }
        if (dp[T] > 0) {
            return dp[T];
        }
        return -1;
    }
};
