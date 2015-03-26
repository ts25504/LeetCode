/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

#include <limits.h>

class Solution {
public:
    int maxProduct(int A[], int n)
    {
        int max_product = A[0];
        int min_product = A[0];
        int res = INT_MIN;
        int cur_max = 0, cur_min = 0;
        for (int i = 1; i < n; ++i)
        {
            cur_max = A[i] * max_product;
            cur_min = A[i] * min_product;
            if (cur_max > cur_min)
            {
                max_product = max(cur_max, A[i]);
                min_product = min(cur_min, A[i]);
            }
            else
            {
                max_product = max(cur_min, A[i]);
                min_product = min(cur_max, A[i]);
            }
            if (max_product > res)
                res = max_product;
        }
        return res;
    }
};
