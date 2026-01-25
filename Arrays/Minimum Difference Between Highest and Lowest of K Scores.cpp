class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        int difference;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - k + 1; i++) {
            difference = nums[i + k - 1] - nums[i];
            mini = min(difference, mini);
        }
        return mini;
    }
};
