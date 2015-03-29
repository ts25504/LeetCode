/*
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& num)
    {
        int left = 0, right = num.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (num[mid] > num[right])
                left = mid + 1;
            else if (num[mid] < num[right])
                right = mid;
            else
                --right;
        }
        return num[left];
    }
};
