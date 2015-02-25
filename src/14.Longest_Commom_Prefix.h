/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    string longestCommomPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return "";
        int min_length = INT_MAX;
        string temp;
        for (const auto& s : strs)
        {
            if (s.empty())
                return "";
            if (min_length > s.length())
            {
                min_length = s.length();
                temp = s;
            }
        }
        vector<int> common_num(min_length);
        string prefix;
        for (const auto& s : strs)
        {
            for (int i = 0; i < temp.length(); ++i)
                if (s[i] == temp[i])
                    common_num[i] += 1;
                else
                    break;
        }
        for (int i = 0; i < temp.length(); ++i)
            if (common_num[i] == strs.size())
                prefix.push_back(temp[i]);
        return prefix;
    }
};
