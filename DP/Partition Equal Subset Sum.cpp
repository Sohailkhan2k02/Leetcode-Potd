//T.C : O(n)
//S.C : O(10001)
class Solution {
public:
    // bool f(int i, vector<int>&nums, int t, int sum, int n,vector<vector<int>>&dp){
    //     if(i>=n && sum!=t) return false;
    //     if(i>=n && sum==t) return true;
    //     if(dp[i][sum]!=-1) return dp[i][sum];

    //     int take=0;
    //     if(sum+nums[i]<=t){
    //         take=f(i+1,nums,t,sum+nums[i],n,dp);
    //     }
    //     int ntake=f(i+1,nums,t,sum,n,dp);
    //     return dp[i][sum]=take||ntake;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size();
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     if(t&1) return false; // odd sum ko 2 bhag me nhi tod skte 23/2=11.5 11.5 not possible
    //     t=t/2;
    //     vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    //     return f(0,nums,t,0,n,dp);
    // }


    bool canPartition(vector<int>& nums) {
        /*
        - can we partition the array into two subsets that have equal sums
        - sum(arr1) = sum(arr2)
        - sum(arr1) + sum(arr2) = total
        - sum(arr1) = sum(arr2) = total / 2
        - if we can find a subset that sums to half, then we know another subset sums to half
        */
        bitset<10001>dp;       // 0 is always achievable => dp[0] = 1
        int t=accumulate(nums.begin(),nums.end(),0);
        if(t&1) return false;
        int a=t/2;
        dp[0]=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=a){
                dp|=dp<<nums[i];
            }
        }
        return dp[a];
    }
};
