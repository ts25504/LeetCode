/*
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        map<char, int> index;
        vector<int> len;
        int max_length = 1;

        for (auto c = 'a'; c != 'z'+1; ++c)
            index[c] = -1;
        len.push_back(1);
        index[s[0]] = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (index[s[i]] == -1)
            {
                len.push_back(len[i-1] + 1);
            }
            else
            {
                len.push_back(i - index[s[i]] > len[i-1] + 1 ?
                        len[i-1] + 1 : i - index[s[i]]);
            }
            index[s[i]] = i;
            max_length = (max_length > len[i] ? max_length : len[i]);
        }
        return max_length;
    }
};
