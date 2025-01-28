//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]==0) return 0;
        int sm=grid[i][j];
        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            sm+=f(nrow,ncol,grid,vis,n,m);
        }
        return sm;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sm=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    sm=max(sm,f(i,j,grid,vis,n,m));
                }
            }
        }
        return sm;
    }
};
