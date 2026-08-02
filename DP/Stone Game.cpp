class Solution {
public:
    int f(int i, int j, bool isAlice, vector<int>&piles, int n,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
    
        if(isAlice){
            int a=piles[i]+f(i+1,j,false,piles,n,dp);
            int b=piles[j]+f(i,j-1,false,piles,n,dp);
            dp[i][j]=max(a,b);
        }
        else{
            int a=f(i+1,j,true,piles,n,dp);
            int b=f(i,j-1,true,piles,n,dp);
            dp[i][j]=min(a,b);
        }
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int s=f(0,n-1,true,piles,n,dp);
        int t=accumulate(piles.begin(),piles.end(),0);
        return s>t-s;
    }
};
