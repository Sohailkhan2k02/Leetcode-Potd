class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> count(2 * n + 2, 0);
        long long curSum = n, lessCnt = 0, ans = 0;
        count[curSum] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                lessCnt += count[curSum];
                curSum++;
            } else {
                curSum--;
                lessCnt -= count[curSum];
            }
            ans += lessCnt;
            count[curSum]++;
        }
        return ans;
    }
};
