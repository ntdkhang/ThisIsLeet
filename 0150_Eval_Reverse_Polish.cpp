#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        // tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        std::stack<int> stack;
        for (std::string token: tokens) {
            if (token == "+") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                stack.push(num1 + num2);
            } else if (token == "-") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                stack.push(num2 - num1);
            } else if (token == "*") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                stack.push(num1 * num2);
            } else if (token == "/") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                stack.push(num2 / num1);
            } else {
                stack.push(std::stoi(token));
            }

        }

        return stack.top();
    }
};
