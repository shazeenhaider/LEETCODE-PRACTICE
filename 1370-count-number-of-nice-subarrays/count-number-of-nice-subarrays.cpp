class Solution {
public:
int atMost(vector<int>& nums, int k) {
    int count = 0;
    int left = 0;
    int right = 0;
    int odd = 0;

    while (right < nums.size()) {

        if (nums[right] % 2 != 0)
            odd++;

        while (odd > k) {
            if (nums[left] % 2 != 0)
                odd--;

            left++;
        }

        count += right - left + 1;

        right++;
    }

    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};