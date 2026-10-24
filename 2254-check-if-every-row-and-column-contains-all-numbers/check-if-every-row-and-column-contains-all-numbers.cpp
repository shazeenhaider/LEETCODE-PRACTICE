class Solution {
public:
    bool isvalid(vector<int>& mat) {
        int n = mat.size();
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int num = mat[i];

            if (freq[num] == 1) return false;
            freq[num]++;
        }

        return true;
    }

    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Check rows
        for (int row = 0; row < n; row++) {
            if (!isvalid(matrix[row])) return false;
        }

        // Check columns
        for (int col = 0; col < n; col++) {
            vector<int> temp;

            for (int row = 0; row < n; row++) {
                temp.push_back(matrix[row][col]);
            }

            if (!isvalid(temp)) return false;
        }

        return true;
    }
};