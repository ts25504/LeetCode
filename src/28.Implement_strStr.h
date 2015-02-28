/*
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

class Solution {
public:
    int strStr(char* haystack, char* needle)
    {
        bool found = true;
        int j = 0;

        if (haystack == NULL || needle == NULL || strlen(haystack) < strlen(needle))
            return -1;
        for (int i = 0; i <= strlen(haystack) - strlen(needle); ++i)
        {
            j = i + strlen(needle);
            found = true;
            for (int k = i; k < j; ++k)
                if (haystack[k] != needle[k-i])
                {
                    found = false;
                    break;
                }
            if (found)
                return i;
        }
        return -1;
    }
};
