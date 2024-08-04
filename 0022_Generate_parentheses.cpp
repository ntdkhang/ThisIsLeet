#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::string> result;
    std::vector<std::string> generateParenthesis(int n) {
        std::string st = "";
        generateParenthesis(0, 0, "", n);
        return result;
    }

    void generateParenthesis(int left, int right, std::string st, int n) {
        if (left + right == n * 2) {
            result.push_back(st);
        }

        if (left < n) {
            generateParenthesis(left + 1, right, st + "(", n);
        }

        if (right < left) {
            generateParenthesis(left, right + 1, st + ")", n);
        }
    }
};
