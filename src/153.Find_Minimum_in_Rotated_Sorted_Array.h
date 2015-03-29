/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    int findMin(vector<int>& num)
    {
        return binarySearch(num, 0, num.size() - 1);
    }
    int binarySearch(vector<int>& num, int left, int right)
    {
        if (left == right)
            return num[left];
        int mid = (left + right) / 2;
        if (num[mid] > num[left])
        {
            if (num[left] > num[right])
                return binarySearch(num, mid + 1, right);
            else
                return binarySearch(num, left, mid - 1);
        }
        else if (num[right] > num[mid])
        {
            if (m == 0 || num[m] < num[m - 1])
                return num[m];
            else
                return binarySearch(num, left, mid - 1);
        }
        else
            return min(num[left], num[right]);
    }
    */
    int findMin(vector<int>& num)
    {
        int left = 0, right = num.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2; // Avoid left + right overflow.
            if (num[mid] > num[right])
                left = mid + 1;
            else
                right = mid;
        }
        return num[left];
    }
};
