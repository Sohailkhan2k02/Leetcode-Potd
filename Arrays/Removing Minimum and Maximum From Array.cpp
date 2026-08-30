class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[minIdx] > nums[i])
                minIdx = i;

            if(nums[maxIdx] < nums[i])
                maxIdx = i;
        }

        int right = max(minIdx, maxIdx);
        int left = min(minIdx, maxIdx);

        int res = right + 1;
        res = min(res, n - left);
        res = min(res, (left + 1) + (n - right));

        return res;
    }
};
