/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n)
    {
        if (n == 0)
        {
            vector<vector<int> > res;
            return res;
        }
        vector<vector<int> > res(n, vector<int>(n, 0));
        int sz = n * n;
        int x = 0, y = 0;
        int cnt = 1;
        res[0][0] = cnt;
        while (cnt < sz)
        {
            while (y < n-1 && res[x][y+1] == 0)
            {
                ++cnt;
                res[x][y+1] = cnt;
                ++y;
            }
            while (x < n-1 && res[x+1][y] == 0)
            {
                ++cnt;
                res[x+1][y] = cnt;
                ++x;
            }
            while (y > 0 && res[x][y-1] == 0)
            {
                ++cnt;
                res[x][y-1] = cnt;
                --y;
            }
            while (x > 0 && res[x-1][y] == 0)
            {
                ++cnt;
                res[x-1][y] = cnt;
                --x;
            }
        }
        return res;
    }
};
