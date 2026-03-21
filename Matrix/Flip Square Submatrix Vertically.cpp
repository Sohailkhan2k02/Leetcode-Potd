class Solution {
private:
    void reverse(vector<vector<int>> &grid,int r,int c,int k){
        int endr = r + k, endc = c + k;
        for(int j = c;j < endc;j++){
            int top = r, bottom = endr - 1;
            while(top < bottom) swap(grid[top++][j],grid[bottom--][j]);
        }
    }
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        reverse(grid,x,y,k);
        return grid;
    }
};
