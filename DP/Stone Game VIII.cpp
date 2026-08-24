class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pref(n);
        pref[0]=stones[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+stones[i];
        }
        vector<int> dp(n);
        dp[n-1]=pref[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=max(pref[i]-dp[i+1],dp[i+1]);
        }
        return dp[1];
    }
};
