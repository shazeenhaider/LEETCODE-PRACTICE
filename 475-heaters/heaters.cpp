
class Solution {
public:

    // Check whether all houses are covered with radius mid
    bool isPossible(vector<int>& houses, vector<int>& heaters, int mid) {

        for (int i = 0; i < houses.size(); i++) {

            int house = houses[i];

            // Find first heater >= current house
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int minDist = INT_MAX;

            // Check nearest heater on the right
            if (it != heaters.end()) {
                int rightDist = abs(*it - house);
                minDist = min(minDist, rightDist);
            }

            // Check nearest heater on the left
            if (it != heaters.begin()) {
                int leftDist = abs(*prev(it) - house);
                minDist = min(minDist, leftDist);
            }

            // If nearest heater is farther than radius mid
            if (minDist > mid) {
                return false;
            }
        }

        // Every house is covered
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        // Sort both arrays
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int left = 0;

        int right = max(houses.back(), heaters.back())
                  - min(houses.front(), heaters.front());

        int ans = right;

        // Binary search on radius
        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (isPossible(houses, heaters, mid)) {

                ans = mid;

                // Try smaller radius
                right = mid - 1;
            }
            else {

                // Radius is insufficient
                left = mid + 1;
            }
        }

        return ans;
    }
};
