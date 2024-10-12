class Solution {
public:
    bool f(int i, int j, int k, string s1,string s2, string s3,int n,int m,vector<vector<int>>&dp){
        if(k==s3.size()) return 1;
        if(i==n && s2[j]!=s3[k]) return 0;
        if(j==m && s1[i]!=s3[k]) return 0;
        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<n && s1[i]==s3[k] && s2[j]!=s3[k]){
            return dp[i][j]=f(i+1,j,k+1,s1,s2,s3,n,m,dp);
        }
        else if(j<m && s2[j]==s3[k] && s1[i]!=s3[k]){
            return dp[i][j]=f(i,j+1,k+1,s1,s2,s3,n,m,dp);
        }
        else{
            return dp[i][j]=f(i+1,j,k+1,s1,s2,s3,n,m,dp)||f(i,j+1,k+1,s1,s2,s3,n,m,dp);
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(s3.size()!=n+m) return 0;
        return f(0,0,0,s1,s2,s3,n,m,dp);
    }
};