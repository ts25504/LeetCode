/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int max_length = 0;
        string res, cur;
        int left = 0, right = 0;
        for (int i = 0; i < 2 * s.length() - 1; ++i)
        {
            left = i / 2;
            right = i / 2;
            if (i % 2)
                ++right;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            cur = s.substr(left+1, right-left-1);
            if (cur.length() > max_length)
            {
                max_length = cur.length();
                res = cur;
            }
        }
        return res;
    }
};
