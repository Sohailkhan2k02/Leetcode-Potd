class Solution {
public:
    int memo(int idx, int target, vector<int>& nums, int x,vector<vector<int>> &dp) {
        if (target == 0) {
            return 1;
        }
        if (idx == 0) {
            return (nums[idx]==target);
        }
        int MOD=1e9+7;
        if(dp[idx][target]!=-1)return dp[idx][target];
        int nottpick = memo(idx - 1, target, nums, x,dp);
        int pick = 0;
        if (pow(nums[idx], x) <= target) {
            pick = memo(idx - 1, target - pow(nums[idx], x), nums, x,dp);
        }
        return dp[idx][target]=(pick + nottpick)%(MOD);
    }
    int numberOfWays(int n, int x) {
        vector<int> nums(300);
        for (int i = 0; i < 300; i++) {
            nums[i] = i + 1;
        }
        int MOD=1e9+7;
        vector<vector<int>>dp(300,vector<int>(301,-1));
        return memo(299, n, nums, x,dp)%MOD;
    }
};
