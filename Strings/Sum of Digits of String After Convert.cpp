//T.C : O(n*k)
//S.C : O(n)
class Solution {
public:
    int getLucky(string s, int k) {
        using ll=long long;
        string num="";
        int n=s.size();
        for(int i=0; i<n; i++){
            num+=to_string(s[i]-'a'+1);
        }
        // for(auto i:num) cout<<i<<" ";
        ll sum=0;
        for(int i=0; i<k; i++){
            ll a=0;
            for(int i=0; i<num.size(); i++){
                a+=num[i]-'0';
            }
            num=to_string(a);
            sum=a;
        }
        // cout<<sum<<" ";
        return sum;
    }
};
