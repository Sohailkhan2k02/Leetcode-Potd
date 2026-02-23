class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int total = 1 << k;
        vector<bool> seen(total, false);

        int mask = 0;
        int limit = total - 1;

        for (int i = 0; i < n; i++) {
            mask = ((mask << 1) & limit) | (s[i] - '0');

            if (i >= k - 1 && !seen[mask]) {
                seen[mask] = true;
                total--;
                if (total == 0) return true;
            }
        }
        return false;
    }
};
