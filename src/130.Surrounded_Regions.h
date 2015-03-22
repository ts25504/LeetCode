/*
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        if (m < 3)
            return;
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n-1] == 'O')
                bfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m-1][j] == 'O')
                bfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] == 'Y') ? 'O' : 'X';
    }
    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        board[i][j] = 'Y';
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (i > 0 && board[i-1][j] == 'O')
            {
                q.emplace(i-1, j);
                board[i-1][j] = 'Y';
            }
            if (i < board.size() - 1 && board[i+1][j] == 'O')
            {
                q.emplace(i+1, j);
                board[i+1][j] = 'Y';
            }
            if (j > 0 && board[i][j-1] == 'O')
            {
                q.emplace(i, j-1);
                board[i][j-1] = 'Y';
            }
            if (j < board[0].size() - 1 && board[i][j+1] == 'O')
            {
                q.emplace(i, j+1);
                board[i][j+1] = 'Y';
            }
        }
    }
};
