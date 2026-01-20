class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.length();
        vector<vector<char>> mat(numRows, vector<char>(n, ' '));

        int row = 0, col = 0;
        bool down = true;

        for (char c : s) {
            mat[row][col] = c;

            if (down) {
                if (row == numRows - 1) {
                    down = false;
                    row--;
                    col++;
                } else {
                    row++;
                }
            } else {
                if (row == 0) {
                    down = true;
                    row++;
                } else {
                    row--;
                    col++;
                }
            }
        }

        // Read row by row
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= col; j++) {
                if (mat[i][j] != ' ') {
                    ans += mat[i][j];
                }
            }
        }

        return ans;
    }
};
