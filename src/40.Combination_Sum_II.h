/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target)
    {
        vector<vector<int> > res;
        vector<int> comb;
        sort(num.begin(), num.end());
        dfs(num, target, res, 0, comb, 0);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
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
            dfs(candidates, target, res, cur, comb, i+1);
            cur -= candidates[i];
            comb.pop_back();
        }
    }
};
