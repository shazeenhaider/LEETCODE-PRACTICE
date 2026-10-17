class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>nums,int i,vector<int>temp){
        int n = nums.size();
        if(i==n){//base case
            ans.push_back(temp);
            return;
        }
        //include the current element
        temp.push_back(nums[i]);
        solve(nums,i+1,temp);
        //exclude krne s pahle pop bhi krege element ko
        temp.pop_back();
        //exclude the current element
        solve(nums,i+1,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return ans;


    }
};