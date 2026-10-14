class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string ans;

        while (num-- > 0) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? ans : "";
    }
};
