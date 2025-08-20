class Solution {
public:
    int f(int i, int j,vector<vector<int>>&matrix,int n, int m,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=f(i,j+1,matrix,n,m,dp);
        int down=f(i+1,j,matrix,n,m,dp);
        int right_diagonal=f(i+1,j+1,matrix,n,m,dp);
        return dp[i][j]=1+min({right,down,right_diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt+=f(i,j,matrix,n,m,dp);
            }
        }
        return cnt;
    }
};
