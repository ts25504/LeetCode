/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
         vector<int> num3(num1.length() + num2.length());
         string res;
         reverse(num1.begin(), num1.end());
         reverse(num2.begin(), num2.end());
         for (int i = 0; i < num1.length(); ++i)
             for (int j = 0; j < num2.length(); ++j)
             {
                num3[i+j] += (num1[i] - '0') * (num2[j] - '0');
                num3[i+j+1] += num3[i+j] / 10;
                num3[i+j] %= 10;
             }
         int i = num3.size() - 1;
         for (; i > 0 && num3[i] == 0; --i);
         for (; i >= 0; --i)
             res += to_string(num3[i]);

         return res;
    }
};
