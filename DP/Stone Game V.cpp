class Solution {
public:
    int f(int i, int j, vector<int>&stoneValue,int n,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int t=0;
        for(int x=i;x<=j;x++){
            t+=stoneValue[x];
        }
        int l=0,maxi=0;
        for(int x=i; x<j; x++){
            l+=stoneValue[x];
            int r=t-l;
            if(l==r){
                maxi=max(maxi,l+f(i,x,stoneValue,n,dp));
                maxi=max(maxi,r+f(x+1,j,stoneValue,n,dp));
            }
            else if(l<r){
                maxi=max(maxi,l+f(i,x,stoneValue,n,dp));
            }
            else{
                maxi=max(maxi,r+f(x+1,j,stoneValue,n,dp));
            }
        }
        return dp[i][j]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,stoneValue,n,dp);
    }
};
