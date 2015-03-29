/*
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 */

#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int tmp = s[i] - 64;
            sum = sum * 26 + tmp;
        }
        return sum;
    }
};
