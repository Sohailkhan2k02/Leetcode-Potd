class Solution { 
public: 
    using ll = long long; 
    const ll mod = 1e9+7; 
 
    vector<vector<ll>> dp; 
 
    ll solve(int n, int k){ 
        if(k==0 || k==n) return 1; 
 
        if(dp[n][k]!=-1) return dp[n][k]; 
 
        return dp[n][k] = (solve(n-1, k-1) + solve(n-1, k))%mod; 
    } 
    
    int numberOfSets(int n, int k) { 
        int N = n+k-1; 
        int R = 2*k; 
 
        dp.assign(N+1, vector<ll>(R+1, -1)); 
        return solve(N, R); 
    } 
};
