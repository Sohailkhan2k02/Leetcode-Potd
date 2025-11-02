class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ind1=0,ind2=0;
        for(auto i:guards){
            vis[i[0]][i[1]]=3;
        }
        for(auto i:walls){
            vis[i[0]][i[1]]=2;
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(auto i:guards){
            int row=i[0],col=i[1];
            for(int k=0; k<4; k++){
                int nrow=row,ncol=col;
                while(1){
                    nrow+=delrow[k];
                    ncol+=delcol[k];
                    if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || vis[nrow][ncol]==3 || vis[nrow][ncol]==2) break;
                    vis[nrow][ncol]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};
