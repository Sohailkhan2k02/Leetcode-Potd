class Solution {
public:
    bool in2DBounders(int x, int y, int n, int m){
        return (x >= 0 && y >= 0  && x < n && y < m);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int DX[4] = {0,0,1,-1};
        int DY[4] = {1,-1,0,0};
        int n = heights.size(), m = heights[0].size();
        // 0 -> pacific , 1 -> atlantic
        vector<vector<vector<int>>>can(n, vector<vector<int>>(m, vector<int>(2, 0)));
        queue<pair<int,int>>bfs;
        for(int i = 0; i < n; i++){
            can[i][0][0] = 1;
            can[i][m-1][1] = 1;
            bfs.push({i, 0});
            bfs.push({i, m-1});
        }
        for(int i = 0; i < m; i++){
            can[0][i][0] = 1;
            can[n-1][i][1] = 1;
            bfs.push({0, i});
            bfs.push({n-1, i});
        }
        set<vector<int>>ret;
        while(!bfs.empty()){
            int x = bfs.front().first;
            int y = bfs.front().second;
            if(can[x][y][0] + can[x][y][1] == 2)ret.insert({x, y});
            bfs.pop();
            for(int d = 0; d < 4; d++){
                int dx = x + DX[d], dy = y + DY[d];
                if(!in2DBounders(dx, dy, n, m))continue;
                if(heights[x][y] > heights[dx][dy])continue;
                if(can[dx][dy][0] == can[x][y][0] &&
                   can[dx][dy][1] == can[x][y][1]) continue;
                can[dx][dy][0] |= can[x][y][0];
                can[dx][dy][1] |= can[x][y][1];
                bfs.push({dx, dy});
            }
        }
        vector<vector<int>>ans;
        for(auto &i: ret){
            ans.push_back(i);
        }
        return ans;
    }
};
