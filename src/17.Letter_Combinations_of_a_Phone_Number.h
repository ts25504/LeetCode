/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> letter_table = {"", "", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty())
            return res;
        string s;
        dfs(0, res, digits, s, letter_table);
        return res;
    }
    void dfs(int i, vector<string>& res, string& digits, string& s,
             const vector<string>& letter_table)
    {
        if (i == digits.length())
        {
            res.push_back(s);
            return;
        }
        for (int j = 0; j < letter_table[digits[i]-48].length(); ++j)
        {
            s.push_back(letter_table[digits[i]-48][j]);
            dfs(i+1, res, digits, s, letter_table);
            s.pop_back();
        }
    }
};
