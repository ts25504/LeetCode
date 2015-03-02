/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
        int row[9][9] = {0}, column[9][9] = {0}, sub_boxes[9][9] = {0};
        int num = 0, k = 0;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                {
                    k = i / 3 + 3 * (j / 3);
                    num = board[i][j] - '0' - 1;
                    if (row[i][num] || column[j][num] || sub_boxes[k][num])
                        return false;
                    row[i][num] = 1;
                    column[j][num] = 1;
                    sub_boxes[k][num] = 1;
                }
        return true;
    }
};
