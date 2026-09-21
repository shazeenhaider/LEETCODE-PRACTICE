class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix = 0;
        int minPrefix = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            prefix += x;

            maxSum = max(maxSum, prefix - minPrefix);

            minPrefix = min(minPrefix, prefix);
        }

        return maxSum;
    }
};