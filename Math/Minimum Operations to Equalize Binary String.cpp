class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size();
        long long zero = 0;

        for (char c : s)
            if (c == '0') zero++;

        if (zero == 0) return 0;

        long long one = n - zero;

        for (long long ops = 1; ops <= n; ops++) {
            long long totalFlip = ops * 1LL * k;

            // parity condition
            if ((totalFlip - zero) % 2 != 0)
                continue;

            if (ops % 2 == 1) {
                if (totalFlip >= zero &&
                    totalFlip <= zero * ops + one * (ops - 1))
                    return ops;
            } else {
                if (totalFlip >= zero &&
                    totalFlip <= zero * (ops - 1) + one * ops)
                    return ops;
            }
        }

        return -1;
    }
};
