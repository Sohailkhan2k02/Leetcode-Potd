class Solution {
public:
    vector<int> dp;
    int M=1e9+7;
    
    int func(char ch, int num) {
        if (num < 26) return 1;
        
        if (dp[num] != -1) return dp[num];
        
        int curr = (1LL*func('a', num - 26) + 1LL*func('b', num - 25))%M;
        
        return dp[num] = curr;
    }
    
    int lengthAfterTransformations(string s, int t) {
        int cnt = 0;
        unordered_map<char, int> mp;
        int n = s.length();
        
        dp.resize(t + 1, -1);
        
        for (int i = 0; i < n; i++) {
            int temp = 'z' - s[i];
            if (t > temp) {
                if (mp.find(s[i]) != mp.end()) {
                    cnt = (1LL*cnt+mp[s[i]])%M;
                } else {
                    int len = func('a', t - temp - 1) + func('b', t - temp);
                    cnt = (1LL*cnt+len)%M;
                    mp[s[i]] = len;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
