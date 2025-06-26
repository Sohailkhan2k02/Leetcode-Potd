class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0,ctr=-1;
        long long num=0;
        for(int i=s.size()-1;i>=0;i--){
            ctr++;
            if(s[i]=='0'){
                ans++;
                continue;
            }
            else if(ctr<=64&&num<=k){
                num+=pow(2,ctr);
                if(num<=k)ans++;
            }
        }
        return ans;
    }
};
