class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();

        auto rectArea = [&](int r1, int c1, int r2, int c2) -> int {
            int minR = n, maxR = -1, minC = m, maxC = -1;
            for (int i = r1; i <= r2; ++i) {
                for (int j = c1; j <= c2; ++j) {
                    if (g[i][j]) {
                        if (i < minR) minR = i;
                        if (i > maxR) maxR = i;
                        if (j < minC) minC = j;
                        if (j > maxC) maxC = j;
                    }
                }
            }
            if (maxR == -1) return 1; 
            return (maxR - minR + 1) * (maxC - minC + 1);
        };

        int ans = INT_MAX;

        
        for (int c1 = 0; c1 <= m - 3; ++c1) {
            for (int c2 = c1 + 1; c2 <= m - 2; ++c2) {
                int A = rectArea(0, 0,     n - 1, c1);
                int B = rectArea(0, c1+1,  n - 1, c2);
                int C = rectArea(0, c2+1,  n - 1, m - 1);
                ans = min(ans, A + B + C);
            }
        }

        
        for (int r1 = 0; r1 <= n - 3; ++r1) {
            for (int r2 = r1 + 1; r2 <= n - 2; ++r2) {
                int A = rectArea(0,     0, r1,     m - 1);
                int B = rectArea(r1+1,  0, r2,     m - 1);
                int C = rectArea(r2+1,  0, n - 1,  m - 1);
                ans = min(ans, A + B + C);
            }
        }

        
        for (int c = 0; c <= m - 2; ++c) {
            for (int r = 0; r <= n - 2; ++r) {
                int L  = rectArea(0, 0,     n - 1, c);
                int TR = rectArea(0, r,     0, 0); 
                int A  = rectArea(0,     c + 1, r,     m - 1);
                int B  = rectArea(r + 1, c + 1, n - 1, m - 1);
                ans = min(ans, L + A + B);
            }
        }

       
        for (int c = 0; c <= m - 2; ++c) {
            for (int r = 0; r <= n - 2; ++r) {
                int R  = rectArea(0,     c + 1, n - 1, m - 1);
                int A  = rectArea(0,     0,     r,     c);
                int B  = rectArea(r + 1, 0,     n - 1, c);
                ans = min(ans, R + A + B);
            }
        }

        
        for (int r = 0; r <= n - 2; ++r) {
            for (int c = 0; c <= m - 2; ++c) {
                int TOP = rectArea(0, 0,     r,     m - 1);
                int A   = rectArea(r + 1, 0,     n - 1, c);
                int B   = rectArea(r + 1, c + 1, n - 1, m - 1);
                ans = min(ans, TOP + A + B);
            }
        }

       
        for (int r = 0; r <= n - 2; ++r) {
            for (int c = 0; c <= m - 2; ++c) {
                int BOT = rectArea(r + 1, 0,     n - 1, m - 1);
                int A   = rectArea(0,     0,     r,     c);
                int B   = rectArea(0,     c + 1, r,     m - 1);
                ans = min(ans, BOT + A + B);
            }
        }

        return ans;
    }

private:
    int n, m;
    vector<vector<int>> g;
};
