/*
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix)
    {
        int n = matrix.size();
        vector<vector<int> > tmp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tmp[i][j] = matrix[n-j-1][i];
        matrix = tmp;
    }
};
