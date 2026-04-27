class Solution {
public:
    vector<vector<pair<int,int>>> dir ={
        {{{0,0},{0,0}}},
        {{{0,-1},{0,1}}},//1
        {{{1,0},{-1,0}}},//2
        {{{0,-1},{1,0}}},//3
        {{{0,1},{1,0}}},//4
        {{{0,-1},{-1,0}}},//5
        {{{0,1},{-1,0}}},//6
    };
    bool dfs(int i,int j,vector<vector<int>> & grid,vector<vector<bool>>& vis){
        int n = grid.size(),m=grid[0].size();

        vis[i][j]=true;
        if(i==n-1 && j==m-1) return true;
        int val = grid[i][j];
        for(int k = 0; k < dir[val].size();k++){
            int new_i = i + dir[val][k].first;
            int new_j = j + dir[val][k].second;

            bool ok = false;
            
            if(new_i >=0 && new_j >=0 && new_i <n && new_j<m ){
                int newVal = grid[new_i][new_j];
                for(auto[dx,dy]:dir[newVal]){
                    if (new_i + dx == i && new_j + dy == j) {
                        ok = true;
                        break;
                    }
                }
                if(!ok) continue;
                if(!vis[new_i][new_j]) {if(dfs(new_i,new_j,grid,vis)) return true;}
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        return dfs(0,0,grid,vis);
    }
};
