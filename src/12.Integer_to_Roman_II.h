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
        string roman_table[] =
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
         "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
         "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
         "", "M", "MM", "MMM"};
        return roman_table[num/1000+30] + roman_table[(num/100)%10+20] +
            roman_table[(num/10)%10+10] + roman_table[num%10];
    }
};
