class Solution {
public:

    const vector<int> di = {1, 0, -1, 0};
    const vector<int> dj = {0, 1, 0, -1};

    bool dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, int pre_i, int pre_j, char c){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return false;

        if(grid[i][j]!=c) return false;

        if(visited[i][j]) return true;

        if(!visited[i][j] && grid[i][j]==c){
            visited[i][j]=true;


            for(int k=0; k<4; k++){
                if(i+di[k]!=pre_i || j+dj[k]!=pre_j)
                    if(dfs(i+di[k], j+dj[k], grid, visited, i, j, c)) return true;//down, right, up, left
            }

        }
        return false;

    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                if(!visited[i][j]){
                    if(dfs(i, j, grid, visited, -1, -1, grid[i][j])==true) return true;
                }
            }
        }
        return false;
    }
};
