class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());   // IMPORTANT
        int count = 0;

        // Fix the largest side at index k
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All pairs (i..j-1, j) are valid
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
int triangleNumber(vector<int>& nums) { //BRUTE FORCE T.C O(N3)
        int count=0;
        for(int i=0; i<nums.size(); i++){
            //ith first element
            for(int j=i+1; j<nums.size(); j++){//assume second side
            for(int k=j+1; k<nums.size(); k++){
                int m = nums[i]+nums[j];
                int n =nums[i]+nums[k];
                int p=nums[k]+nums[j];
           if(m>nums[k]&&n>nums[j]&&p>nums[i]){
                count++;
              }
            }
            }
        }
return count;

class Solution {-------------->>>>>>Approach II using binary search
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {

                int sum = nums[i] + nums[j];

                // binary search for first index >= sum
                int left = j + 1, right = n - 1;
                int k = j;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) {
                        k = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                count += (k - j);
            }
        }
        return count;
    }
};

