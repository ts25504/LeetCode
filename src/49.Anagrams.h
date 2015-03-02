/*
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs)
    {
        map<string, int> anagrams;
        vector<string> res;
        string s;
        for (int i = 0; i < strs.size(); ++i)
        {
            s = strs[i];
            sort(s.begin(), s.end());
            if (anagrams.find(s) == anagrams.end())
            {
                anagrams[s] = i;
            }
            else
            {
                if (anagrams[s] >= 0)
                {
                    res.push_back(strs[anagrams[s]]);
                    anagrams[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
