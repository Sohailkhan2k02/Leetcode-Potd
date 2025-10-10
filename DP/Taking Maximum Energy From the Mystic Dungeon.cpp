class Solution {
public:
    int f(int i,vector<int>&p, int k, int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int take=p[i]+f(i+k,p,k,n,dp);
        return dp[i]= take;
    }
    int maximumEnergy(vector<int>& p, int k) {
        int n=p.size();
        vector<int>dp(n,-1);
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi,f(i,p,k,n,dp));
        }
        return maxi;
    }
};
