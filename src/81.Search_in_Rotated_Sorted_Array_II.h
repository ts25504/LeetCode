/*
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?

 * Would this affect the run-time complexity? How and why?

 * Write a function to determine if a given target is in the array.
 */

class Solution {
public:
    bool search(int A[], int n, int target)
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (A[left] == target || A[mid] == target || A[right] == target)
                return true;
            while (mid > left && A[mid] == A[left])
                left++;
            while (mid < right && A[mid] == A[right])
                right--;
            if (left == right)
                break;

            if (A[left] < A[mid])
            { 
                if (A[left] <= target && A[mid] >= target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (A[mid + 1] <= target && A[right] >= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};
