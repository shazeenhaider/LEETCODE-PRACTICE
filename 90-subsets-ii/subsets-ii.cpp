class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s1;
    void solve(vector<int> nums,int i,vector<int>temp){
        int n=nums.size();
        //sort(nums.begin(), nums.end())
        if(i==n){
            if(s1.find(temp) == s1.end()){
                //push in set first
                s1.insert(temp);
                //push to ans;
                ans.push_back(temp);
            }
            return;
        }
        //include
        temp.push_back(nums[i]);
        solve(nums,i+1,temp);
        //backtrack delete
        temp.pop_back();
        solve(nums,i+1,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums,0,temp);
        return ans;
    }
};