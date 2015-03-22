/*
 * Given an array of integers, every element appears three times except for one. Find that single one.
 */

class Solution {
public:
    int singleNumber(int A[], int n)
    {
        int one = 0, two = 0, three = 0;
        int i = 0;
        for (int i = 0; i < n; ++i)
        {
            three = two & A[i];
            two = two | one & A[i];
            one = one | A[i];
            one = one & ~three;
            two = two & ~three;
        }
        return one;
    }
};
