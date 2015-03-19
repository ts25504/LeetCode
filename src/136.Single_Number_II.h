/*
 * Given an array of integers, every element appears twice except for one. Find that single one.
 */

class Solution {
public:
    int singleNumber(int A[], int n)
    {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res ^= A[i];
        return res;
    }
};
