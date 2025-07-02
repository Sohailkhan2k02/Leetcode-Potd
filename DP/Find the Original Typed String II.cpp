//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;
        int total = 1, ucnt = 0;
        vector<int> cnt;
        char b = word[0]; int r = -1;
        for (char c: word) {
            if (b == c) {++r;}
            else {if (r) cnt.push_back(r); total = (long)total * (r+1) % MOD; ++ucnt; b = c; r = 0;}
        }
        if (r) cnt.push_back(r); total = (long)total * (r+1) % MOD; ++ucnt;
        // reduce those invalid cases with length <= k-1
        // if ucnt >= k, then no invalid cases
        if (ucnt >= k) return total;
        // if ucnt <= k-1, then repetitions <= k-1-ucnt,
        int m = cnt.size(); if (!m) return total-1;
        int maxRepeat = k-1-ucnt;
        vector<int> dp(maxRepeat+1, 0);
        dp[0] = 1; // dp[i] are possible cases with repeat >= i
        for (int c: cnt) {
            int addition = 0;
            for (int k = maxRepeat; k != -1; --k) {
                addition += (dp[k-min(k,c)] - dp[k]) % MOD; addition %= MOD;
                dp[k] += addition; dp[k] %= MOD;
            }
        }
        return ((total - dp[0]) % MOD + MOD) % MOD;

    }
};
