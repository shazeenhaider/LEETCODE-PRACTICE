class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum=0;
        int j=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
             j++;
            if(n%j==0){
                //special element found
                sum = sum + nums[i]*nums[i];
            }
        }
        return sum;
    }
};