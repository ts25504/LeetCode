/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target)
    {
        int left = 0, right = n - 1, mid = 0;
        int res = 0;
        while (left < right - 1)
        {
            mid = (left + right) / 2;
            if (A[mid] < target)
                left = mid;
            else
                right = mid;
        }
        if (A[left] >= target)
            res = left;
        else if (A[right] >= target)
            res = right;
        else if (A[right] < target)
            res = right + 1;
        return res;
    }
};
