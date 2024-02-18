// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCount[26];
        for (int i = 0; i < magazine.size(); i++) {
            charCount[magazine[i] - 'a'] += 1;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            charCount[ransomNote[i] - 'a'] -= 1;
        }
        for (int i : charCount) {
            if (i < 0) 
                return false;
        }
        return true;
    }
};
