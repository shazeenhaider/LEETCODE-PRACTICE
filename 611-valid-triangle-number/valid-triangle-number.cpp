class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());   // IMPORTANT
        int count = 0;

        // Fix the largest side at index k
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All pairs (i..j-1, j) are valid
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
