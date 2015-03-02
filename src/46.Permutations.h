/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& num)
    {
        vector<vector<int> > res;
        vector<int> ans;
        map<int, int> visit;
        sort(num.begin(), num.end());
        dfs(num, res, ans, visit);
        return res;
    }
    void dfs(const vector<int>& num, vector<vector<int> >& res,
             vector<int>& ans, map<int, int>& visit)
    {
        if (ans.size() == num.size())
        {
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (visit[num[i]] == 0)
            {
                ans.push_back(num[i]);
                visit[num[i]] = 1;
                dfs(num, res, ans, visit);
                visit[num[i]] = 0;
                ans.pop_back();
            }
        }
    }
};
