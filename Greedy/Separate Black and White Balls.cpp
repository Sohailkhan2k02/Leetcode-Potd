//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        using ll=long long;
        ll n=s.size();
        ll cnt=0;
        ll r=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') cnt++;
            else if(s[i]=='0') r+=cnt;
        }
        return r;
    }
};
