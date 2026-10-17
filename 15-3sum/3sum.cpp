class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //On^3 three loop brute force
        //shuru k 1 element fix kr dia 
        sort(nums.begin(), nums.end());
        set<vector<int>>s1;//pair duplicate dekhega
        for(int i=0; i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    //push to the set
                    s1.insert({nums[i], nums[left], nums[right]});
                   left++;
                   right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
        return vector<vector<int>>(s1.begin(),s1.end());
    }
};