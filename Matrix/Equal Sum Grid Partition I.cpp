class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long>rs(m,0);
        vector<long long>cs(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                     cs[j]+=grid[i][j];
                     if(i==m-1&&j-1>=0){
                        cs[j]+=cs[j-1];
                     }
                    rs[i]+=grid[i][j];
            }
            if(i-1>=0){
                rs[i]+=rs[i-1];
            }
            
        }
        if(rs[m-1]%2==0){
        for(int i=0;i<m;i++){
            if(rs[m-1]/2==rs[i]){
                return true;
            }
        }
        }
        if(cs[n-1]%2==0){
            for(int i=0;i<n;i++){
            if(cs[n-1]/2==cs[i]){
                return true;
            }
        }
        }
        return false;
    }
};
