class Solution {
public:
    typedef long long ll;
    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prevPrev, int prev,
                       bool isLimitedByActualNumber, bool isLeadingZeroes) {

        if (curr == n) {
            return {1, 0}; // one complete number formed, no more waviness to add
        }

        // Memoization: only when both flags are false and prev state is valid
        if (!isLimitedByActualNumber && !isLeadingZeroes && prevPrev >= 0 && prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev],
                        dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers   = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitedByActualNumber ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {

            bool isNewLeadingZero = isLeadingZeroes && (digit == 0);

            int newPrevPrev = prev;
            int newPrev     = isNewLeadingZero ? -1 : digit;

            auto [remNumbers, remWaveScore] = solve(
                curr + 1, newPrevPrev, newPrev,
                isLimitedByActualNumber && (digit == limitDigit),
                isNewLeadingZero
            );

            // Check if 'prev' forms a peak or valley with its two neighbors
            if (!isNewLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remNumbers; // this peak/valley exists in all future numbers
                }
            }

            totalNumbers   += remNumbers;
            totalWaveScore += remWaveScore;
        }

        // Store result only for memoizable states
        if (!isLimitedByActualNumber && !isLeadingZeroes && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev]  = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if (num < 100) return 0; // need at least 3 digits for a peak/valley

        memset(dpTotalNumbers,  -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);
        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};
