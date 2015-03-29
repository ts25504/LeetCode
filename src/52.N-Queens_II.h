/*
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n)
    {
        vector<int> cols(n, 0);
        return dfs(cols, 0);
    }
    bool isValid(const vector<int>& cols, int depth)
    {
        for (int i = 0; i < depth; ++i)
        {
            if ((cols[i] == cols[depth]) ||
                (depth - i == cols[depth] - cols[i]) ||
                (depth - i == cols[i] - cols[depth]))
                return false;
        }
        return true;
    }
    int dfs(vector<int>& cols, int depth)
    {
        if (depth == cols.size())
            return 1;
        int total = 0;
        for (int row = 0; row < cols.size(); ++row)
        {
            cols[depth] = row;
            if (isValid(cols, depth))
                total += totalNQueens(cols, depth + 1);
        }
        return total;
    }
};
