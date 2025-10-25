class Solution {
public:
    int totalMoney(int n) {
        int step = 1, count = 1, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i > 1 && i % 7 == 1) {
                step++;
                ans += step;
                count = step + 1;
            } else {
                ans += count;
                count++;
            }
        }
        return ans;
    }
};
