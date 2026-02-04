class Solution {
public:
    long long maxSumTrionic(const vector<int>& nums) {
        const long long INF = -1e17;
        long long result = INF, a = INF, b = INF, c = INF;
        long long prev = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            auto na = INF, nb = INF, nc = INF;
            if (curr > prev) { // increasing, update first and third state
                na = max(a, prev) + curr;
                nc = max(b, c) + curr;
            } else if (curr < prev) { // decreasing, update second state
                nb = max(a, b) + curr;
            }
            a = na, b = nb, c = nc;
            result = max(result, c);
            prev = curr;
        }
        return result;
    }
};
