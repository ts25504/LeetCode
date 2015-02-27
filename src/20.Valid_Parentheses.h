/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')' || c == '}' || c == ']')
            {
                if (st.empty())
                    return false;
                if (c == ')' && st.top() != '(')
                    return false;
                if (c == '}' && st.top() != '{')
                    return false;
                if (c == ']' && st.top() != '[')
                    return false;
                else
                    st.pop();
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
