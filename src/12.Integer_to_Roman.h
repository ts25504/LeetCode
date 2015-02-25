/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num)
    {
        string res;
        int pos = 1, pos_int = 0;
        while (pos * 10 <= num)
            pos *= 10;
        while (num > 0)
        {
            pos_int = num / pos;
            if (pos == 1000)
                for (int i = 0; i < pos_int; ++i)
                    res += "M";
            else if (pos == 100)
            {
                if (pos_int < 4)
                    for (int i = 0; i < pos_int; ++i)
                        res += "C";
                else if (pos_int == 4)
                    res += "CD";
                else if (pos_int == 5)
                    res += "D";
                else if (pos_int < 9)
                {
                    res += "D";
                    for (int i = 0; i < pos_int - 5; ++i)
                        res += "C";
                }
                else
                    res += "CM";
            }
            else if (pos == 10)
            {
                if (pos_int < 4)
                    for (int i = 0; i < pos_int; ++i)
                        res += "X";
                else if (pos_int == 4)
                    res += "XL";
                else if (pos_int == 5)
                    res += "L";
                else if (pos_int < 9)
                {
                    res += "L";
                    for (int i = 0; i < pos_int - 5; ++i)
                        res += "X";
                }
                else
                    res += "XC";
            }
            else
            {
                if (pos_int < 4)
                    for (int i = 0; i < pos_int; ++i)
                        res += "I";
                else if (pos_int == 4)
                    res += "IV";
                else if (pos_int == 5)
                    res += "V";
                else if (pos_int < 9)
                {
                    res += "V";
                    for (int i = 0; i < pos_int - 5; ++i)
                        res += "I";
                }
                else
                    res += "IX";
            }
            num %= pos;
            pos /= 10;
        }
        return res;
    }
};
