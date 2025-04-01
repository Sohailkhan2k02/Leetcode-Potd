//T.C : O(n)
//S.C : O(recursive stack space+n)
#define ll long long
class Solution {
public:
    int n;
    ll f(ll i,vector<vector<int>>& questions,vector<ll>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        ll nottake=f(i+1,questions,dp);
        ll take=questions[i][0]+f(i+1+questions[i][1],questions,dp);
        return dp[i]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<ll>dp(n+1,-1);
        return f(0,questions,dp);
    }
};
