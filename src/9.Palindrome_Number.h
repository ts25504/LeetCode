/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int left_pos = 1;
        int right_pos = 10;
        int left = 0, right = 0;
        while (left_pos * 10 <= x)
        {
            if (left_pos == 1000000000)
                break;
            left_pos *= 10;
        }
        while (left_pos >= right_pos)
        {
            left = x / left_pos;
            right = x % right_pos;
            x = x % left_pos / right_pos;
            if (left == right)
            {
                left_pos /= 100;
            }
            else
                return false;
        }
        return true;
    }
};
