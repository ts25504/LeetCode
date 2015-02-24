/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <string>
#include <limits.h>
#include <cctype>

using namespace std;

class Solution {
public:
    int atoi(string str)
    {
        if (str.empty())
            return 0;
        int pos = 0;
        int num = 0;
        bool negative = false;
        int res = 0;
        while (isspace(str[pos]))
            ++pos;
        if (str[pos] == '+')
        {
            negative = false;
            ++pos;
        }
        else if (str[pos] == '-')
        {
            negative = true;
            ++pos;
        }

        for (int i = pos; i < str.length(); ++i)
        {
            if (isdigit(str[i]))
            {
                num = static_cast<int>(str[i]) - 48;
                if (negative)
                {
                    if (-res < (INT_MIN + num) / 10)
                        return INT_MIN;
                }
                else
                {
                    if (res > (INT_MAX - num) / 10)
                        return INT_MAX;
                }
                res = 10 * res + num;
            }
            else
                break;
        }
        return negative ? -res : res;
    }
};
