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
        int left = 0, right = 0, mid = 0;
        int neg = 0;
        vector<vector<int> > res;
        if (num.size() < 3)
            return res;
        for (int i = 0; i < num.size(); ++i)
            if (num[i] <= 0 && num[i+1] > 0)
                neg = i;
        int sz = num.size();

        for (int i = 0; i <= neg; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
            for (int j = i+1; j < sz; ++j)
            {
                left = i + 1;
                right = j - 1;
                while (left <= right)
                {
                    mid = (left + right) / 2;
                    if (num[i] + num[j] + num[mid] == 0)
                    {
                        res.push_back({num[i], num[mid], num[j]});
                        break;
                    }
                    else if (num[i] + num[j] + num[mid] < 0)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
