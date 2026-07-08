class Solution {
    const long long MOD = 1e9+7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        // Precompute powers of 10
        vector<long long> pw(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            pw[i] = (pw[i-1] * 10) % MOD;
        }
        
        // Prefix arrays (1-indexed to handle L-1 cleanly)
        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_num(n + 1, 0);
        vector<int> pref_len(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            
            // Carry over previous values
            pref_sum[i+1] = pref_sum[i];
            pref_len[i+1] = pref_len[i];
            pref_num[i+1] = pref_num[i];
            
            if(d > 0) {
                pref_sum[i+1] += d;
                pref_len[i+1] += 1;
                pref_num[i+1] = (pref_num[i] * 10 + d) % MOD;
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for(auto &q : queries) {
            int L = q[0] + 1; // Convert to 1-indexed
            int R = q[1] + 1;
            
            long long range_sum = pref_sum[R] - pref_sum[L-1];
            int range_len = pref_len[R] - pref_len[L-1];
            
            // Substring hash formula: Hash(L,R) = Hash(R) - Hash(L-1) * 10^(Length)
            long long shift = (pref_num[L-1] * pw[range_len]) % MOD;
            long long range_num = (pref_num[R] - shift + MOD) % MOD;
            
            ans.push_back((range_num * range_sum) % MOD);
        }
        
        return ans;
    }
};
