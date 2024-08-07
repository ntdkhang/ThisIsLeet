#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int right = *std::max_element(piles.begin(), piles.end());
        int left = 1;
        int minEatingSpeed = right, mid;


        while (left <= right) {
            mid = (left + right) / 2;
            if (!canEanWithSpeed(piles, h, mid)) {
                left = mid + 1;
            } else {
                minEatingSpeed = mid;
                right = mid - 1;
            }
        }

        return minEatingSpeed;
    }

    bool canEanWithSpeed(std::vector<int>& piles, int h, int k) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += piles[i] / k;
            if (piles[i] % k != 0) {
                time++;
            }
            if (time > h)
                return false;
        }
        return true;
    }
};

