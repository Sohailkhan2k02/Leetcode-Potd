class Solution {
public:
    // int f(int i, bool isAlice, vector<int>&stoneValue, int n,vector<vector<int>>&dp){
    //     if(i>=n) return 0;
    //     if(dp[i][isAlice]!=-1) return dp[i][isAlice];
    //     int maxi=0;
    //     if(isAlice){
    //         maxi=INT_MIN;
    //     }
    //     else{
    //         maxi=INT_MAX;
    //     }
    //     int a=0;
    //     for(int x=1; x<=3 && i+x<=n; x++){
    //         a+=stoneValue[i+x-1];
    //         if(isAlice){
    //             maxi=max(maxi,a+f(i+x,false,stoneValue,n,dp));
    //         }
    //         else{
    //             maxi=min(maxi,f(i+x,true,stoneValue,n,dp));
    //         }
    //     }
    //     return dp[i][isAlice]=maxi;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     int n=stoneValue.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,-1));
    //     int s=f(0,true,stoneValue,n,dp);
    //     int t=accumulate(stoneValue.begin(),stoneValue.end(),0);
    //     if(s>t-s){
    //         return "Alice";
    //     }
    //     else if(s<t-s){
    //         return "Bob";
    //     }
    //     else return "Tie";
    // }


    // 1D DP
    int f(int i, vector<int>&stoneValue, int n, vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int total=0,maxi=INT_MIN;
        for(int x=1;x<=3 && i+x<=n;x++){
            total+=stoneValue[i+x-1];
            maxi=max(maxi,total-f(i+x,stoneValue,n,dp));
        }
        return dp[i]=maxi;
    }
    string stoneGameIII(vector<int>& stoneValue){
        int n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int d=f(0,stoneValue,n,dp);
        if(d>0){
            return "Alice";
        }
        else if(d<0){
            return "Bob";
        }
        else return "Tie";
    }
};
