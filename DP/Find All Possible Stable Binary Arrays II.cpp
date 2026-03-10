class Solution {
public:
    const int MOD = 1e9+7;

    int dp[1005][1005][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=min(zero,limit);i++)
            dp[i][0][0] = 1;

        for(int j=1;j<=min(one,limit);j++)
            dp[0][j][1] = 1;

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){

                long long val0 = (1LL*dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                if(i-limit-1 >= 0)
                    val0 = (val0 - dp[i-limit-1][j][1] + MOD) % MOD;
                dp[i][j][0] = val0;

                long long val1 = (1LL*dp[i][j-1][1] + dp[i][j-1][0]) % MOD;
                if(j-limit-1 >= 0)
                    val1 = (val1 - dp[i][j-limit-1][0] + MOD) % MOD;
                dp[i][j][1] = val1;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
