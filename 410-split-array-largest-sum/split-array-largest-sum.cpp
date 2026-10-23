
class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int limit) {
        int parts = 1, sum = 0;

        for (int num : nums) {
            if (sum + num > limit) {
                parts++;
                sum = num;
            } else {
                sum += num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;

        for (int num : nums) {
            low = max(low, num);
            high += num;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};