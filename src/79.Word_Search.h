/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word)
    {
        int x = 0, y = 0;
        int max_sz = 0;
        for (int i = 0; i < board.size(); ++i)
            if (board[i].size() > max_sz)
                max_sz = board[i].size();

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == word[0])
                {
                    x = i;
                    y = j;
                    vector<vector<int> > visit = {board.size(), vector<int>(max_sz, 0)};
                    string ans, res;
                    ans.push_back(word[0]);
                    visit[x][y] = 1;
                    dfs(board, word, ans, 1, x, y, res, visit);
                    if (res == word)
                        return true;
                }
        return false;
    }

    void dfs(const vector<vector<char> >& board, const string& word,
             string& ans, int n, int x, int y, string& res,
             vector<vector<int> >& visit)
    {
        if (ans == word)
        {
            res = ans;
            return;
        }

        if (x - 1 >= 0 && !visit[x-1][y] && board[x-1][y] == word[n])
        {
            ans.push_back(board[x-1][y]);
            visit[x-1][y] = 1;
            dfs(board, word, ans, n+1, x-1, y, res, visit);
            visit[x-1][y] = 0;
            ans.pop_back();
        }
        if (x + 1 < board.size() && !visit[x+1][y] && board[x+1][y] == word[n])
        {
            ans.push_back(board[x+1][y]);
            visit[x+1][y] = 1;
            dfs(board, word, ans, n+1, x+1, y, res, visit);
            visit[x+1][y] = 0;
            ans.pop_back();
        }
        if (y - 1 >= 0 && !visit[x][y-1] && board[x][y-1] == word[n])
        {
            ans.push_back(board[x][y-1]);
            visit[x][y-1] = 1;
            dfs(board, word, ans, n+1, x, y-1, res, visit);
            visit[x][y-1] = 0;
            ans.pop_back();
        }
        if (y + 1 < board[x].size() && !visit[x][y+1] && board[x][y+1] == word[n])
        {
            ans.push_back(board[x][y+1]);
            visit[x][y+1] = 1;
            dfs(board, word, ans, n+1, x, y+1, res, visit);
            visit[x][y+1] = 0;
            ans.pop_back();
        }
        return;
    }
};
