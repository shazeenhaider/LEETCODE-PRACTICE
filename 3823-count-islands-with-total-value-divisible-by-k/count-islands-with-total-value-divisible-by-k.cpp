class Solution {
public:
    long long dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n ||
            grid[row][col] == 0) {
            return 0;
        }

        long long sum = grid[row][col];
        grid[row][col] = 0;  // visited mark

        sum += dfs(row - 1, col, grid); // up
        sum += dfs(row + 1, col, grid); // down
        sum += dfs(row, col - 1, grid); // left
        sum += dfs(row, col + 1, grid); // right

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long  sum = dfs(i, j, grid);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};