
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        // Check 3x3 grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isSafe(board, i, j, ch)) {
                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            // Backtracking
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
