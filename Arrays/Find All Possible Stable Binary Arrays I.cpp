class Solution {
public:
    const int MOD = 1e9+7;
    int dp[201][201][2][201];
    
    int solve(int z,int o,int last,int used,int zero,int one,int limit){
        if(z==zero && o==one) return 1;

        if(z>zero || o>one) return 0;
        if(used>limit) return 0;

        if(dp[z][o][last][used] != -1)
            return dp[z][o][last][used];

        long long res = 0;

        if(z<zero){
            if(last==0){
                if(used<limit)
                    res = (res + solve(z+1,o,0,used+1,zero,one,limit)) % MOD;
            }
            else{
                res = (res + solve(z+1,o,0,1,zero,one,limit)) % MOD;
            }
        }

        if(o<one){
            if(last==1){
                if(used<limit)
                    res = (res + solve(z,o+1,1,used+1,zero,one,limit)) % MOD;
            }
            else{
                res = (res + solve(z,o+1,1,1,zero,one,limit)) % MOD;
            }
        }

        return dp[z][o][last][used] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long res = 0;

        if(zero>0)
            res = (res + solve(1,0,0,1,zero,one,limit)) % MOD;

        if(one>0)
            res = (res + solve(0,1,1,1,zero,one,limit)) % MOD;

        return res;
    }
}
