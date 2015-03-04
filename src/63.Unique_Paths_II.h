/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int path[m][n];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                path[i][j] = 0;
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            path[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            path[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    path[i][j] = 0;
                else
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        return path[m-1][n-1];
    }
};
