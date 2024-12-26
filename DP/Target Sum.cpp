//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int f(int i, vector<int>&nums, int k, int sum,int t, int n,vector<vector<int>>&dp){
        if(i>=n && sum!=k) return 0;
        if(i>=n && sum==k) return 1;
        if(dp[i][sum+t]!=-1) return dp[i][sum+t];
        
        int pos=f(i+1,nums,k,sum+nums[i],t,n,dp);
        int neg=f(i+1,nums,k,sum-nums[i],t,n,dp);
        return dp[i][sum+t]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int k) {
        int n=nums.size();
        int t=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>((2*t)+1,-1));
        return f(0,nums,k,0,t,n,dp);
    }
};
