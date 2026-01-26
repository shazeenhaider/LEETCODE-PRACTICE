class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;

        // 1. Collect positive elements
        for (int x : nums) {
            if (x >= 0) {
                temp.push_back(x);
            }
        }

        int n = temp.size();
        if (n == 0) return nums;

        k = k % n;

        // 2. Rotate temp by k (right rotation)
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());
        reverse(temp.begin(), temp.end());



        // 3. Put back rotated positives
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = temp[idx++];
            }
        }

        return nums;
    }
// | RIGHT    | whole → first k → rest |
// | LEFT     | first k → rest → whole |

 };
