class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        // Step 1: Store nums and corresponding costs
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], cost[i]});
        }

        // Step 2: Sort according to nums
        sort(arr.begin(), arr.end());

        // Step 3: Calculate total weight
        long long totalWeight = 0;

        for (auto &p : arr) {
            totalWeight += p.second;
        }

        // Step 4: Find weighted median
        long long prefixWeight = 0;
        int target = 0;

        for (auto &p : arr) {
            prefixWeight += p.second;

            if (prefixWeight * 2 >= totalWeight) {
                target = p.first;
                break;
            }
        }

        // Step 5: Calculate minimum cost
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += abs((long long)nums[i] - target) * cost[i];
        }

        return ans;
    }
};