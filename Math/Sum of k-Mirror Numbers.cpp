class Solution {
public:
    bool isKPalindrome(string s, int k) {
        long long num = stoll(s);
        string baseK = "";
        while (num > 0) {
            baseK += (num % k) + '0';
            num /= k;
        }
        string rev = baseK;
        reverse(rev.begin(), rev.end());
        return baseK == rev;
    }

    long long kMirror(int k, int n) {
        int l = 1;
        long long sum = 0;
        
        while (n > 0) {
            int len = (l + 1) / 2;
            long long minnum = pow(10, len - 1);
            long long maxnum = pow(10, len) - 1;

            for (long long i = minnum; i <= maxnum; ++i) {
                string firsthalf = to_string(i);
                string secondhalf = firsthalf;
                reverse(secondhalf.begin(), secondhalf.end());

                string pal;
                if (l % 2 == 0)
                    pal = firsthalf + secondhalf;
                else
                    pal = firsthalf + secondhalf.substr(1);

                if (isKPalindrome(pal, k)) {
                    sum += stoll(pal);
                    n--;
                    if (n == 0) break;
                }
            }
            l++; // Increment the length for next round
        }

        return sum;
    }
};
