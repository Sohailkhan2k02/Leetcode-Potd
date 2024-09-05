//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        using ll=long long;
        int m=rolls.size();
        ll sum=accumulate(rolls.begin(),rolls.end(),0LL);
        ll a=0, total=n+m;
        a=((mean*(total))-sum);
        cout<<a<<" ";
        if(6*n<a || a<0 || a<n) return {};
        vector<int>res(n,1);
        a-=n;
        for (int i=n-1;i>=0 && a>0;i--){
            int add = min(a,5LL);
            res[i]+=add;
            a-=add;
        }
        return res;
    }
};
