class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitLength = 0;
        
        for (int i = 1; i <= n; i++) {
            
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            ans = ((ans << bitLength) % MOD + i) % MOD;
        }
        
        return (int)ans;
    }
};
