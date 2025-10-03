class Solution {
public:
    class cmp {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));


        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], 0, j});
            vis[0][j] = true;
            pq.push({heightMap[n-1][j], n-1, j});
            vis[n-1][j] = true;
        }
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], i, 0});
            vis[i][0] = true;
            pq.push({heightMap[i][m-1], i, m-1});
            vis[i][m-1] = true;
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = 0;

        while (!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            int height = temp[0], r = temp[1], c = temp[2];

            for (int i = 0; i < 4; i++) {
                int new_r = r + dirs[i][0];
                int new_c = c + dirs[i][1];

                if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m && !vis[new_r][new_c]) {
                    vis[new_r][new_c] = true;
                    ans += max(0, height - heightMap[new_r][new_c]);
                    pq.push({max(height, heightMap[new_r][new_c]), new_r, new_c});
                }
            }
        }

        return ans;
    }
};
