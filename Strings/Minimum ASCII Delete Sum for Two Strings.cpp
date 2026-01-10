class Solution {
public:
    int f(int i, int j, string &s1, string &s2, int n, int m,vector<vector<int>>&dp){
        if(i>=n){
            int sum=0;
            for(int k=j; k<m; k++){
                sum+=(int)s2[k];
            }
            return sum;
        }
        if(j>=m){
            int sum=0;
            for(int k=i; k<n; k++){
                sum+=(int)s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i+1,j+1,s1,s2,n,m,dp);
        }
        else{
            int del1=int(s1[i])+f(i+1,j,s1,s2,n,m,dp);
            int del2=int(s2[j])+f(i,j+1,s1,s2,n,m,dp);
            return dp[i][j]=min(del1,del2);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,s1,s2,n,m,dp);
    }
};
