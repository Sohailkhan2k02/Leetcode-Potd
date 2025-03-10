//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    using ll=long long;
    ll f(string s,int k) {
        int n=s.size();
        int i=0,j=0;
        ll cnt=0;
        unordered_map<char,ll> m1;
        ll c1=0;
        while(j<n) {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') {
                m1[s[j]]++;
            } else c1++;

            while(m1.size()>=5 && c1>k) {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                    m1[s[i]]--;
                    if(m1[s[i]]==0) {
                        m1.erase(s[i]);
                    }
                } else {
                    c1--;
                }
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    long long countOfSubstrings(string s, int k) {
        return f(s,k)-f(s,k-1);
    }
};
