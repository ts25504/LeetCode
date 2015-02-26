/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& num, int target)
    {
        sort(num.begin(), num.end());
        int left = 0, right = 0;
        int res = 1000000000;
        int sz = num.size();

        for (int i = 0; i < sz-2; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
            left = i + 1;
            right = sz - 1;
            while (left < right)
            {
                if (abs(num[left] + num[right] + num[i] - target) <
                        abs(res - target))
                    res = num[left] + num[right] + num[i];

                if (num[left] + num[right] + num[i] < target)
                {
                    while (left < sz && num[left] == num[left+1])
                        ++left;
                    ++left;
                }
                else if (num[left] + num[right] + num[i] > target)
                {
                    while (right > 0 && num[right] == num[right-1])
                        --right;
                    --right;
                }
                else if (num[left] + num[right] + num[i] == target)
                    return target;
            }
        }
        return res;
    }
};
