/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        stack<char> st;
        vector<char> ch_vec = {'(', ')'};
        vector<string> res;
        string s;
        int i = 0;
        dfs(st, ch_vec, res, s, 0, n);
        return res;
    }
    void dfs(stack<char>& st, const vector<char>& ch_vec, vector<string>& res,
             string s, int i, int n)
    {
        if (i == 2 * n)
        {
            if (st.empty())
                res.push_back(s);
            return;
        }

        for (int j = 0; j < ch_vec.size(); ++j)
        {
            if (st.empty() && ch_vec[j] == ')')
                continue;
            s.push_back(ch_vec[j]);
            if (ch_vec[j] == '(')
                st.push('(');
            else if (ch_vec[j] == ')')
                st.pop();
            dfs(st, ch_vec, res, s, i+1, n);
            if (s.back() == '(')
                st.pop();
            else if (s.back() == ')')
                st.push('(');
            s.pop_back();
        }
    }
    /*
     * TLE
     *
    void dfs(const vector<char>& ch_vec, vector<string>& res,
             string s, int i, int n)
    {
        if (i == 2 * n)
        {
            stack<char> st;
            for (int j = 0; j < s.length(); ++j)
            {
                if (s[j] == '(')
                    st.push('(');
                if (s[j] == ')')
                {
                    if (st.empty())
                        return;
                    st.pop();
                }
            }

            if (st.empty())
                res.push_back(s);
            return;
        }
        for (int j = 0; j < ch_vec.size(); ++j)
        {
            s.push_back(ch_vec[j]);
            dfs(ch_vec, res, s, i+1, n);
            s.pop_back();
        }
    }
    */
};
