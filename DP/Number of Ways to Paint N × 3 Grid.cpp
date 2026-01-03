class Solution {
public:
    static const int mod = 1e9 + 7;

    // Multiply two 2x2 matrices
    vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    ans[i][j] = (1LL * ans[i][j] + 1LL * a[i][k] * b[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }

    // Binary Exponentiation for Matrix
    vector<vector<int>> power(vector<vector<int>> base, int b) {
        vector<vector<int>> ans = {{1, 0}, {0, 1}}; // Identity Matrix
        while(b) {
            if(b & 1) ans = mul(ans, base);
            base = mul(base, base);
            b /= 2;
        }
        return ans;
    }

    int numOfWays(int n) {
        if (n == 0) return 0;
        
        // Base Transformation Matrix
        vector<vector<int>> base = {{3, 2}, {2, 2}};
        
        // Initial State for n=1: ABA=6, ABC=6
        vector<vector<int>> initial = {{6, 6}}; 

        // Calculate T^(n-1)
        vector<vector<int>> T_pow = power(base, n - 1);

        // Final result = initial * T_pow
        vector<vector<int>> ans = mul(initial, T_pow);
        
        return (ans[0][0] + ans[0][1]) % mod;
    }
};
