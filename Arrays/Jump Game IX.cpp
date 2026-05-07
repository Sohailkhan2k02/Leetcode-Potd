class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suf_min(n);
        suf_min[n - 1] = nums[n - 1];

        // Build suffix minimum array
        for (int i = n - 2; i >= 0; i--) {
            suf_min[i] = min(nums[i], suf_min[i + 1]);
        }

        vector<int> ans(n);

        int start = 0;
        int pref_max = nums[0];
        int seg_max = nums[0];

        for (int i = 0; i < n - 1; i++) {
            pref_max = max(pref_max, nums[i]);
            seg_max = max(seg_max, nums[i]);

            if (pref_max <= suf_min[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = seg_max;
                }

                start = i + 1;

                if (start < n) {
                    pref_max = nums[start];
                    seg_max = nums[start];
                }
            }
        }

        // Fill remaining segment
        seg_max = nums[start];
        for (int i = start; i < n; i++) {
            seg_max = max(seg_max, nums[i]);
        }

        for (int j = start; j < n; j++) {
            ans[j] = seg_max;
        }

        return ans;
    }
}; 
