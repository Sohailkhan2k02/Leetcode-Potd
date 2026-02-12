class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;  
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            int maxFreq = 0;
            
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                
                if (freq[idx] == 0) {
                    distinct++;
                }
                
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);
                
                int len = j - i + 1;
                
                if (len == distinct * maxFreq) {
                    ans = max(ans, len);
                }
            }
        }
        
        return ans;
    }
};
