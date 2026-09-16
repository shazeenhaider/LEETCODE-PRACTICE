class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int r, int c, int index) {

        // All characters matched
        if (index == word.size())
            return true;

        // Invalid cell
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[index])
            return false;

        // Mark visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Check 4 directions
        bool found =
            solve(board, word, r + 1, c, index + 1) ||
            solve(board, word, r - 1, c, index + 1) ||
            solve(board, word, r, c + 1, index + 1) ||
            solve(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == word[0] &&
                    solve(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};