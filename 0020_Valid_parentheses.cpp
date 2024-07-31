#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            if (c == '}') {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            if (c == ')') {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            if (c == ']') {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
