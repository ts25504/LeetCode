/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid)
    {
        int sum = 0;
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            grid[i][0] = sum + grid[i][0];
            sum = grid[i][0];
        }
        sum = 0;
        for (int j = 0; j < n; ++j) {
            grid[0][j] = sum + grid[0][j];
            sum = grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};
