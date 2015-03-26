/*
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string& s)
    {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp)
            s = tmp + " " + s;
        if (s[0] == ' ')
            s = "";
    }
};
