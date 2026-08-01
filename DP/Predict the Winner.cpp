class Solution {
public:
    int f(int i, int j, bool isPlayer1, vector<int>&nums, int n, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        if(isPlayer1){
            int a=nums[i]+f(i+1,j,false,nums,n,dp);
            int b=nums[j]+f(i,j-1,false,nums,n,dp);
            dp[i][j]=max(a,b);
        }
        else{
            int a=f(i+1,j,true,nums,n,dp);
            int b=f(i,j-1,true,nums,n,dp);
            dp[i][j]=min(a,b);
        }
        return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int s=f(0,n-1,true,nums,n,dp);
        int t=accumulate(nums.begin(),nums.end(),0);
        return s>=t-s;
    }
};
