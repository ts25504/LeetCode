/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *         A solution set is:
 *             (-1, 0, 1)
 *             (-1, -1, 2)
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num)
    {
        sort(num.begin(), num.end());
        int left = 0, right = 0;
        vector<vector<int> > res;
        if (num.size() < 3)
            return res;
        int sz = num.size();

        for (int i = 0; i < sz-2; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
            left = i + 1;
            right = sz - 1;
            while (left < right)
            {
                if (num[left] + num[right] == -num[i])
                {
                    res.push_back({num[i], num[left], num[right]});
                    while (left < sz && num[left] == num[left+1])
                        ++left;
                    while (right > 0 && num[right] == num[right-1])
                        --right;
                    ++left;
                    --right;
                }
                else if (num[left] + num[right] < -num[i])
                {
                    while (left < sz && num[left] == num[left+1])
                        ++left;
                    ++left;
                }
                else
                {
                    while (right > 0 && num[right] == num[right-1])
                        --right;
                    --right;
                }
            }
        }
        return res;
    }
};
