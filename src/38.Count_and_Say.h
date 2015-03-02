/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        string temp_str, cur_str = "1";
        int cnt = 0, i = 0;
        while (--n > 0)
        {
            i = 0;
            while (i < cur_str.length())
            {
                cnt = 1;
                while (cur_str[i] == cur_str[i+1])
                {
                    ++i;
                    ++cnt;
                }
                temp_str.push_back(cnt + '0');
                temp_str += cur_str[i];
                ++i;
            }
            cur_str = temp_str;
            temp_str = "";
        }
        return cur_str;
    }
};
