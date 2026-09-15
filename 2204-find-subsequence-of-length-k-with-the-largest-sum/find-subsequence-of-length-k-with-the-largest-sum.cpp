class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back({nums[i], i});
        }

        sort(ans.begin(), ans.end(), greater<pair<int, int>>());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(ans[i].second);
        }

        sort(result.begin(), result.end());

        for (int i = 0; i < k; i++) {
            result[i] = nums[result[i]];
        }

        return result;
    }
};