class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, maxi = 0;

        while (r < n) {
            sum += nums[r]; // Add current element to sum
            hash[nums[r]]++; // Count the frequency

            // If duplicate found, shrink from left
            while (hash[nums[r]] > 1) {
                sum -= nums[l]; // Subtract leftmost value from sum
                hash[nums[l]]--;
                if (hash[nums[l]] == 0) {
                    hash.erase(nums[l]); // Clean up map
                }
                l++;
            }

            maxi = max(maxi, sum); // Update maximum
            r++;
        }

        return maxi;
    }
};
