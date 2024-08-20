//Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^3)
class Solution {
public:
    int f(int i,int m,bool isAlice,vector<int>&piles,int n,vector<vector<vector<int>>>&dp){
        if(i>=n) return 0;
        if(dp[i][m][isAlice]!=-1) return dp[i][m][isAlice];
        int maxi=0;
        if(isAlice){
            maxi=INT_MIN;
        }
        else{
            maxi=INT_MAX;
        }
        int a=0;
        for(int x=1; x<=2*m && i+x<=n; x++){
            a+=piles[i+x-1];
            if(isAlice){
                maxi=max(maxi,a+f(i+x,max(m,x),false,piles,n,dp));
            }
            else{
                maxi=min(maxi,f(i+x,max(m,x),true,piles,n,dp));
            }
        }
        return dp[i][m][isAlice]=maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1, vector<int>(2,-1)));
        return f(0,1,true,piles,n,dp);
    }
};
