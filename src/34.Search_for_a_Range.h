/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 5, 8, 8, 8, 8, 8, 10, 10
 * 5, 7, 7, 7, 7, 10
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        vector<int> res = {-1, -1};
        if (n == 0)
            return res;
        int start_pos = 0, end_pos = n-1, mid = 0;
        while (start_pos < end_pos - 1)
        {
            mid = (start_pos + end_pos) / 2;
            if (A[mid] < target)
                start_pos = mid;
            else
                end_pos = mid;
        }
        if (A[start_pos] == target)
            res[0] = start_pos;
        else if (A[end_pos] == target)
            res[0] = end_pos;
        end_pos = n - 1;
        while (start_pos < end_pos - 1)
        {
            mid = (start_pos + end_pos) / 2;
            if (A[mid] > target)
                end_pos = mid;
            else
                start_pos = mid;
        }
        if (A[end_pos] == target)
            res[1] = end_pos;
        else if (A[start_pos] == target)
            res[1] = start_pos;
        return res;
    }
};
