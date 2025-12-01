class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long left = 0, right = total / n, ans = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            long long usable = 0;
            for (long long b : batteries) {
                usable += min(b, mid);
            }

            if (usable >= mid * n) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
