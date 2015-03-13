/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 */

#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle)
    {
        int n = triangle.size();
        int min_sum[n];

        if (triangle.empty())
            return 0;

        for (int i = 0; i < n; ++i)
            min_sum[i] = INT_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (i == n - 1)
                    min_sum[j] = triangle[i][j];
                else
                    min_sum[j] = triangle[i][j] + min(min_sum[j], min_sum[j+1]);
            }
        }
        return min_sum[0];
    }
};
