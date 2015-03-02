/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > res;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, 0, comb, 0);
        return res;
    }

    void dfs(const vector<int>& candidates, int target,
             vector<vector<int> >& res, int cur, vector<int> comb, int cur_i)
    {
        if (cur == target)
        {
            res.push_back(comb);
            return;
        }
        if (cur > target)
            return;

        for (int i = cur_i; i < candidates.size(); ++i)
        {
            comb.push_back(candidates[i]);
            cur += candidates[i];
            dfs(candidates, target, res, cur, comb, i);
            cur -= candidates[i];
            comb.pop_back();
        }
    }
};
