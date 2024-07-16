#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::map<int, int> count;
        std::vector<int> keys;

        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            count[*it]++;
        }

        for (std::map<int, int>::iterator imap = count.begin(); imap != count.end(); imap++) {
            keys.push_back(imap->first);
        }

        for (int i = 0; i < keys.size(); i++) {
            // decrement count of the first number;
            int firstNum = keys[i];
            count[firstNum]--;
            for (int j = i; j < keys.size(); j++) {
                int secondNum = keys[j];
                if (count[secondNum] > 0) {
                    count[secondNum]--;
                    int thirdNum = -(firstNum + secondNum);
                    if (thirdNum >= secondNum && count.find(thirdNum) != count.end() && count[thirdNum] > 0) {
                        result.push_back(std::vector<int>{firstNum, secondNum, thirdNum});
                    }
                    count[secondNum]++;
                }
            }

            // increment count of first
            count[firstNum]++;
        }

        return result;
    }
};
