//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid, int &sum, vector<vector<int>>&vis, int &maxi){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        sum+=grid[i][j];
        maxi=max(maxi,sum);
        vis[i][j]=1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            dfs(nrow,ncol,grid,sum,vis,maxi);
        }
        sum-=grid[i][j];
        vis[i][j]=0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sum;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    sum=0;
                    dfs(i,j,grid,sum,vis,maxi);
                }
            }
        }
        return maxi;
    }
};
