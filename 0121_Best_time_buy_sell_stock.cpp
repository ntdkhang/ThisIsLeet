#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minBuy = prices[0];
        int maxProf = 0;

        for (std::vector<int>::iterator it = prices.begin(); it != prices.end(); it++) {
            if (*it < minBuy) {
                minBuy = *it;
            }
            else if (*it - minBuy > maxProf) {
                maxProf = *it - minBuy;
            }
        }

        return maxProf;
    }
};
