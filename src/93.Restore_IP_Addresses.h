/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12)
            return res;
        int l = s.length();
        for (int i = 1; i < s.length() - 2; ++i)
            for (int j = i + 1; j < s.length() - 1; ++j)
                for (int k = j + 1; k < s.length(); ++k)
                {
                    string s0 = s.substr(0, i);
                    if (s0.length() > 3 || (s0[0] == '0' && s0.length() > 1))
                        continue;
                    string s1 = s.substr(i, j-i);
                    if (s1.length() > 3 || (s1[0] == '0' && s1.length() > 1))
                        continue;
                    string s2 = s.substr(j, k-j);
                    if (s2.length() > 3 || (s2[0] == '0' && s2.length() > 1))
                        continue;
                    string s3 = s.substr(k, l-k);
                    if (s3.length() > 3 || (s3[0] == '0' && s3.length() > 1))
                        continue;
                    if (stoi(s0) <= 255 && stoi(s1) <= 255 &&
                            stoi(s2) <=255 && stoi(s3) <= 255)
                        res.push_back(s0+"."+s1+"."+s2+"."+s3);
                }
        return res;
    }
};
