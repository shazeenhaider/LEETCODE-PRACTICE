class Solution {
public:
    bool isValid(vector<char>& mat) {
        vector<int> freq(10, 0);

        for (int i = 0; i < 9; i++) {
            char num = mat[i];

            if (num == '.') {
                continue;
            }

            int digit = num - '0';

            if (freq[digit] == 1) {
                return false;
            }

            freq[digit]++;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int row = 0; row < 9; row++) {
            if (!isValid(board[row])) {
                return false;
            }
        }

        // Check columns
        for (int col = 0; col < 9; col++) {
            vector<char> temp;

            for (int row = 0; row < 9; row++) {
                temp.push_back(board[row][col]);
            }

            if (!isValid(temp)) {
                return false;
            }
        }

        // Check 3x3 boxes
        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {

                vector<int> freq(10, 0);

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        char num = board[startRow + i][startCol + j];

                        if (num == '.') {
                            continue;
                        }

                        int digit = num - '0';

                        if (freq[digit] == 1) {
                            return false;
                        }

                        freq[digit]++;
                    }
                }
            }
        }

        return true;
    }
};