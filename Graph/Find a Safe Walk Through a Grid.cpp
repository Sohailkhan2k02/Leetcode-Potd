class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        deque<pair<int,int>> q;
        q.push_back({0, 0});

        vector d(n,vector(m, -1));
        d[0][0] = grid[0][0];
        int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
        while(q.size())
        {
            auto [x, y] = q.front();
            q.pop_front();
            for(int i = 0;i < 4; ++i)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if(d[tx][ty]!=-1) continue;
                d[tx][ty] = d[x][y] + grid[tx][ty];
                if(grid[tx][ty] == 0) q.push_front({tx, ty});
                else q.push_back({tx, ty});
            }
        }
        // cout<<d[n - 1][m - 1]<<endl;
        return d[n - 1][m - 1] < health;
    }
};
