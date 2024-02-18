// Given two binary string a and b, return their sum as a binary string 

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public: 
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        // a = "100101", b = "10111"
        string sum;

        char s, r, a_char, b_char;
        for (int i = 0; i < a.size(); i++) {
            if (i > b.size()) { b_char = 0; }
            else { b_char = b[b.size() - i - 1]; }
        }       


        return "0";
    }
};
