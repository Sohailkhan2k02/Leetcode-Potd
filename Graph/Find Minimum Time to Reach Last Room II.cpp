class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int> > a, f[2];
    int m, n, res, MAX = 2000000000;
    bool done[2][800][800];

    int calc_dist(){
        int i, j, k, v, nx, ny, p, w, d, q;
        set<pair<pair<int, int>, pair<int, int> > > S;
        f[0] = a;
        f[1] = a;
        for (i = 0; i < m; ++i) 
            for (j = 0; j < n; ++j){
                f[0][i][j] = f[1][i][j] = MAX;
                done[0][i][j] = done[1][i][j] = false;
            }
                
        f[0][0][0] = 0;
        S.insert({{0, 0}, {0, 0}});
        while (S.size() > 0){
            d = S.begin()->first.first;
            q = S.begin()->first.second;
            i = S.begin()->second.first;
            j = S.begin()->second.second;
            S.erase(S.begin());
            if (done[q][i][j] || f[q][i][j] == MAX) continue;
            if (f[q][i][j] != d) continue;
            done[q][i][j] = true;
            for (k = 0; k < 4; ++k){
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !done[1 - q][nx][ny]){
                    v = max(a[nx][ny] + (q + 1), f[q][i][j] + (q + 1));
                    if (v < f[1 - q][nx][ny]){
                        f[1 - q][nx][ny] = v;
                        S.insert({{v, 1 - q}, {nx, ny}});
                    }
                }
            }
        }

        return min(f[0][m - 1][n - 1], f[1][m - 1][n - 1]);
    }
    
    int minTimeToReach(vector<vector<int>>& aa) {
        int i, j;
        a = aa;
        m = a.size();
        n = a[0].size();
        return calc_dist();
    }
};
