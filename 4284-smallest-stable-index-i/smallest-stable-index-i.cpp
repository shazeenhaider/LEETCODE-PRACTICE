class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {

            int maxx = INT_MIN;
            int minn = INT_MAX;

            // Maximum in nums[0...i]
            for (int j = 0; j <= i; j++) {
                maxx = max(maxx, nums[j]);
            }

            // Minimum in nums[i...n-1]
            for (int j = i; j < nums.size(); j++) {
                minn = min(minn, nums[j]);
            }

            int stablescore = maxx - minn;

            // Smallest stable INDEX
            if (stablescore <= k) {
                return i;
            }
        }

        return -1;
    }
};