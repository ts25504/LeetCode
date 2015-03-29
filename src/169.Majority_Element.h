/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& num)
    {
        int cnt = 0, res = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            if (cnt == 0)
                res = num[i];
            if (res == num[i])
                ++cnt;
            else
                --cnt;
        }
        return res;
    }
};
