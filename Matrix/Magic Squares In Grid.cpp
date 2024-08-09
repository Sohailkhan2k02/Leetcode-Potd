//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    bool isMagic(vector<vector<int>>&grid, int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i+2<n && j+2<m){

            int col1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
            int col2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
            int col3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
            int row1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
            int row2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
            int row3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
            int dia1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
            int dia2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

            if((col1==col2) && (col1==col3) && (col1==row1) && (col1==row2) && (col1==row3) && (col1==dia1) && (col1==dia2)){
                set<int>s{1,2,3,4,5,6,7,8,9};
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        s.erase(grid[i+k][j+l]);
                    }
                }
                return s.empty();
            }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isMagic(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
