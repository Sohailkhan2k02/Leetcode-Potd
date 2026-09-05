class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = INT_MAX;

        vector<int> mx(n);

        // Prefix maximum
        int mxe = nums[0];
        for (int i = 0; i < n; i++) {
            mxe = max(mxe, nums[i]);
            mx[i] = mxe;
        }

        // Suffix minimum
        int mne = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            mne = min(mne, nums[i]);

            if (abs(mx[i] - mne) <= k)
                ans = min(ans, i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
