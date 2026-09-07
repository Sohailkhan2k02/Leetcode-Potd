class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> m(26, -1);
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = 2 * dp[i-1];

            if(m[s[i-1] - 'a'] != -1)
                dp[i] = 2 * dp[i-1] - dp[m[s[i-1] - 'a']];
            
            dp[i] %= MOD;
            m[s[i-1] - 'a'] = i - 1;
        }
        if(dp[n] <= 0)
            dp[n] += MOD;
        return dp[n] - 1;
    }
};
