//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long myPow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            n = n / 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long no_of_even_idx = (n + 1) / 2;  // 0-based indexing
        long long no_of_odd_idx = n / 2;      
        long long ans = myPow(5, no_of_even_idx) * myPow(4, no_of_odd_idx) % MOD;
        return ans;
    }
};
