/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'M')
                res += 1000;
            else if (s[i] == 'C')
                if (s[i+1] == 'M' or s[i+1] == 'D')
                    res -= 100;
                else
                    res += 100;
            else if (s[i] == 'D')
                res += 500;
            else if (s[i] == 'X')
                if (s[i+1] == 'C' or s[i+1] == 'L')
                    res -= 10;
                else
                    res += 10;
            else if (s[i] == 'L')
                res += 50;
            else if (s[i] == 'I')
                if (s[i+1] == 'X' or s[i+1] == 'V')
                    res -= 1;
                else
                    res += 1;
            else
                res += 5;
        }
        return res;
    }
};
