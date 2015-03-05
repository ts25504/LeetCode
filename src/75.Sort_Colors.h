/*
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n)
    {
        int i = 0, j = 0, color = 0;
        while (i < n)
        {
            if (A[i] == color)
                ++i;
            else
            {
                j = n - 1;
                while (j > i)
                {
                    if (A[j] == color)
                    {
                        swap(A[i], A[j]);
                        break;
                    }
                    --j;
                }
                if (i == j)
                    ++color;
            }
        }
    }
};
