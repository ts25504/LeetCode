/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int row_left = 0, row_right = m - 1, row_mid = 0;
        int col_left = 0, col_right = n - 1, col_mid = 0;
        while (row_left <= row_right)
        {
            row_mid = (row_left + row_right) >> 1;
            if (target > matrix[row_mid][0] && target < matrix[row_mid][n-1])
                break;
            else if (matrix[row_mid][n-1] < target)
                row_left = row_mid + 1;
            else if (matrix[row_mid][0] > target)
                row_right = row_mid - 1;
            else
                return true;
        }
        while (col_left <= col_right)
        {
            col_mid = (col_left + col_right) >> 1;
            if (matrix[row_mid][col_mid] == target)
                return true;
            else if (matrix[row_mid][col_mid] < target)
                col_left = col_mid + 1;
            else
                col_right = col_mid - 1;
        }
        return false;
    }
};
