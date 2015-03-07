/*
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& S)
    {
        vector<vector<int> > res;
        vector<int> ans;
        sort(S.begin(), S.end());
        for (int i = 0; i <= S.size(); ++i)
        {
            dfs(res, ans, S, i, 0);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void dfs(vector<vector<int> >& res, vector<int>& ans,
             const vector<int>& S, int n, int cur)
    {
        if (ans.size() == n)
        {
            res.push_back(ans);
            return;
        }
        for (int i = cur; i < S.size(); ++i)
        {
            ans.push_back(S[i]);
            dfs(res, ans, S, n, i+1);
            ans.pop_back();
        }
    }
};
