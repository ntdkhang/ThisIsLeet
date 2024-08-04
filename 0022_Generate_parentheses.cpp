#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::string> result;
    std::vector<std::string> generateParenthesis(int n) {
        std::string st = "";
        std::stack<char> closingStack;
        generateParenthesis(n, st, closingStack);
        return result;
    }

    void generateParenthesis(int n, std::string& st, std::stack<char>& closingStack) {
        if (n == 0) {
            if (!closingStack.empty()) {
                return;
            }
            result.push_back(st);
            return;
        }

        // Not base case
        st.push_back('(');
        closingStack.push(')');
        generateParenthesis(n - 1, st, closingStack);
        st.push_back(')');
        closingStack.pop();
        generateParenthesis(n - 1, st, closingStack);

        // close everyone
        while (!closingStack.empty()) {
            closingStack.pop();
            st.push_back(')');
            generateParenthesis(n - 1, st, closingStack);
        }

        while (st.back() != '(') {
            closingStack.push(')');
            st.pop_back();
        }
        st.pop_back(); // pop the last open
        closingStack.pop(); // pop the last closing
    }
};
