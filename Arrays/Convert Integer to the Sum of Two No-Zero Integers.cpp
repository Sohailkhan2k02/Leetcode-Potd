namespace {

constexpr int MAX_N = 10000;

constexpr bool isNonZeroInteger(int n) {
    while (n) {
        const int d = n % 10;
        if (!d) return false;

        n /= 10;
    }
    return true;
}

constexpr auto g_isNonZeroInteger = []() {
    array<bool, MAX_N + 1> ans = {};
    for (int i = 1; i < size(ans); ++i)
        ans[i] = isNonZeroInteger(i);
    return ans;
}();

constexpr auto g_getNoZeroIntegers = []() {
    array<array<int, 2>, MAX_N + 1> ans = {};
    for (int n = 1; n < size(ans); ++n) {
        for (int i = 1; i < n; ++i) {
            if (g_isNonZeroInteger[i] && g_isNonZeroInteger[n - i]) {
                ans[n] = {i, n - i};
                break;
            }
        }
    }    
    return ans;
}();

}  // namespace

class Solution {
public:
    static vector<int> getNoZeroIntegers(int n) {
        return {g_getNoZeroIntegers[n][0], g_getNoZeroIntegers[n][1]};
    }
};
