//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    int f(int i, string &s, unordered_set<string>&st, vector<int>&dp, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=1+f(i+1,s,st,dp,n);
        string temp="";
        for(int j=i; j<n; j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                take=min(take,f(j+1,s,st,dp,n));
            }
        }
        return dp[i]=take;
    }
    int minExtraChar(string s, vector<string>& d) {
        int n=s.size();
        unordered_set<string>st(d.begin(),d.end());
        vector<int>dp(n,-1);
        return f(0,s,st,dp,n);
    }
};
