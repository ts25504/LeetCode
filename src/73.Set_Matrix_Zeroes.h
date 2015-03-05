/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int visit[m + n];
        for (int i = 0; i < m + n; ++i)
            visit[i] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0)
                {
                    visit[i] = 1;
                    visit[m+j] = 1;
                }
        for (int i = 0; i < m; ++i)
        {
            if (visit[i] == 1)
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        }
        for (int j = m; j < m + n; ++j)
        {
            if (visit[j] == 1)
                for (int i = 0; i < m; ++i)
                    matrix[i][j-m] = 0;
        }
    }
};
