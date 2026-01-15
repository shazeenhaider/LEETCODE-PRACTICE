class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        int m = nums.size();
        for(int i=0; i<m; i++){
            nums[i]=sum+nums[i];
            sum=nums[i];
        }
        return nums;
    }
};