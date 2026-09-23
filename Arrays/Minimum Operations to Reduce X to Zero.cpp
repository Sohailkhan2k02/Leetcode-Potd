class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0;
        int current_sum = 0;
        int max_len = -1;

        for (int r = 0; r < n; r++) {
            current_sum += nums[r];

            while (l <= r && current_sum > target) {
                current_sum -= nums[l];
                l++;
            }

            if (current_sum == target) {
                max_len = max(max_len, r - l + 1);
            }
        }

        return (max_len == -1) ? -1 : n - max_len;
    }
};
