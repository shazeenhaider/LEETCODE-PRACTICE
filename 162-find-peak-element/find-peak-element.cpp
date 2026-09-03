class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int high = nums.size() - 1;

        while (left < high) {
            int mid = left + (high - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Increasing peak is at right
                left = mid + 1;
            }
            else {
                // Decreasing → peak is at mid or on left
                high = mid;
            }
        }

        return left;
    }
};