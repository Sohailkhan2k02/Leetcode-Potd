class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size(), m=grid[0].size();
        vector<vector<long>> prefix(n, vector<long>(m, 1)), suffix(n, vector<long>(m, 1));
        #pragma unroll
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (i==0 && j==0) continue;
                if (j==0) 
                    prefix[i][j]=prefix[i-1][m-1]*grid[i-1][m-1]%12345;
                else
                    prefix[i][j]=prefix[i][j-1]*grid[i][j-1]%12345;
            }
        }
        #pragma unroll
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if (i==n-1 && j==m-1) continue;
                if (j==m-1)
                    suffix[i][j]=suffix[i+1][0]*grid[i+1][0]%12345;
                else
                    suffix[i][j]=suffix[i][j+1]*grid[i][j+1]%12345;
            }
        }
        
        vector<vector<int>> p(n, vector<int>(m, 1));
        #pragma unroll
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
               p[i][j]=prefix[i][j]*suffix[i][j]%12345;
        }
        return p;
    }
};
