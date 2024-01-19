
//https://leetcode.com/submissions/detail/1150252945/
//o(n)
//o(n)
class Solution {
public:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> elements;
        for (auto &token : tokens) {
            if (isOperator(token)) {
                int x = elements.top();
                elements.pop();
                int y = elements.top();
                elements.pop();
                int value = 0;
                if (token == "+") {
                    value = x + y;
                }
                else if (token == "-") {
                    value = y - x;
                }
                else if (token == "*") {
                    value = x * y;
                }
                else if (token == "/"){
                    value = y / x;
                }
                elements.push(value);
            }
            else {
                elements.push(stoi(token));
            }
        }
        return elements.top();
    }
};