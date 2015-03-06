/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > res;
        vector<int> ans;
        vector<int> visit(n, 0);
        dfs(res, ans, visit, n, k, 0);
        return res;
    }
    void dfs(vector<vector<int> >& res, vector<int>& ans, vector<int>& visit,
             int n, int k, int cur)
    {
        if (ans.size() == k)
        {
            res.push_back(ans);
            return;
        }
        for (int i = cur; i < n; ++i)
        {
            if (visit[i] == 0)
            {
                ans.push_back(i+1);
                visit[i] = 1;
                dfs(res, ans, visit, n, k, i);
                visit[i] = 0;
                ans.pop_back();
            }
        }
    }
};
