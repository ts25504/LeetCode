/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        istringstream s1(version1);
        istringstream s2(version2);
        string token;
        vector<int> d1;
        vector<int> d2;

        while (getline(s1, token, '.'))
        {
            string tmp(token);
            d1.push_back(stoi(tmp));
        }
        while (getline(s2, token, '.'))
        {
            string tmp(token);
            d2.push_back(stoi(tmp));
        }
        for (int i = 0; i < min(d1.size(), d2.size()); ++i)
        {
            if (d1[i] > d2[i])
                return 1;
            if (d1[i] < d2[i])
                return -1;
        }
        if (d1.size() < d2.size())
        {
            for (int i = d1.size(); i < d2.size(); ++i)
            {
                if (d2[i] != 0)
                    return -1;
            }
            return 0;
        }
        if (d1.size() > d2.size())
        {
            for (int i = d2.size(); i < d1.size(); ++i)
            {
                if (d1[i] != 0)
                    return 1;
            }
            return 0;
        }
        if (d1.size() == d2.size())
            return 0;
    }
};
