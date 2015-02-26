/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *         A solution set is:
 *         (-1,  0, 0, 1)
 *         (-2, -1, 1, 2)
 *         (-2,  0, 0, 2)
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& num, int target)
    {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        int left = 0, right = 0;
        int sz = num.size();
        if (sz < 4)
            return res;
        for (int i = 0; i < sz-3; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
            for (int j = i+1; j < sz-2; ++j)
            {
                if (j > i+1 && num[j] == num[j-1])
                    continue;
                left = j + 1;
                right = sz - 1;
                while (left < right)
                {
                    if (num[i] + num[j] + num[left] + num[right] == target)
                    {
                        res.push_back({num[i], num[j], num[left], num[right]});
                        while (left < sz && num[left] == num[left+1])
                            ++left;
                        ++left;
                        while (right >= 0 && num[right] == num[right-1])
                            --right;
                        --right;
                    }
                    else if (num[i] + num[j] + num[left] + num[right] < target)
                    {
                        while (left < sz && num[left] == num[left+1])
                            ++left;
                        ++left;
                    }
                    else
                    {
                        while (right >= 0 && num[right] == num[right-1])
                            --right;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
