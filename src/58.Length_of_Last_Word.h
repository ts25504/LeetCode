/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 */

#include <string.h>

class Solution {
public:
    int lengthOfLastWord(const char* s)
    {
        if (s == NULL)
            return 0;
        int len = strlen(s);
        int word_len = 0;
        while (s[len-1] == ' ')
            --len;
        while (s[--len] != ' ' && len >= 0)
            ++word_len;
        return word_len;
    }
};
