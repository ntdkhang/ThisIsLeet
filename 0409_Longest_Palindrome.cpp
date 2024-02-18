// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

#include <string>
#include <vector>

using namespace std;

class Solution {
public: 
    int longestPlaindrome(string s) {
        int odd = 0;
        vector<int> charCount(52, 0);
        for (char c: s) {
            if (isupper(c)) {
                charCount.at(c - 'A' + 26) += 1;
            } else {
                charCount.at(c - 'a') += 1;
            }
        }
        int result = 0;
        for (int count : charCount) {
            if (count % 2 == 0) {
                result += count;
            } else {
                result += count - 1;
                odd = 1;
            }
        }
        return result + odd;
    }
};
