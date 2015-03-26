/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int x = 0, y = 0, z = 0;
        stack<int> s;
        for (const auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                if (str == "+")
                    z = x + y;
                if (str == "-")
                    z = x - y;
                if (str == "*")
                    z = x * y;
                if (str == "/")
                    z = x / y;
                s.push(z);
            }
            else
                s.push(stoi(str));
        }
        return s.top();
    }
};
