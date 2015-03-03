/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > visit(m, vector<int>(n, 0));
        int sz = m * n;
        int x = 0, y = 0;
        int cnt = 1;
        res.push_back(matrix[0][0]);
        visit[0][0] = 1;
        while (cnt < sz)
        {
            while (y < n-1 && visit[x][y+1] == 0)
            {
                res.push_back(matrix[x][y+1]);
                ++cnt;
                visit[x][y+1] = 1;
                ++y;
            }
            while (x < m-1 && visit[x+1][y] == 0)
            {
                res.push_back(matrix[x+1][y]);
                ++cnt;
                visit[x+1][y] = 1;
                ++x;
            }
            while (y > 0 && visit[x][y-1] == 0)
            {
                res.push_back(matrix[x][y-1]);
                ++cnt;
                visit[x][y-1] = 1;
                --y;
            }
            while (x > 0 && visit[x-1][y] == 0)
            {
                res.push_back(matrix[x-1][y]);
                ++cnt;
                visit[x-1][y] = 1;
                --x;
            }
        }
        return res;
    }
};
