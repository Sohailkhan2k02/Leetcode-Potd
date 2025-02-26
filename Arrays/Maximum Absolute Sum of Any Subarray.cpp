//T.C : O(n)
//S.C : O(1)
#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
static int fastIO = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
// Paste the Class here-
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        long long maxPrefix = 0, minPrefix = 0, pSum = 0, result = 0;

        for (int num : nums)
        {
            pSum += num;
            result = max(result, max(abs(pSum - minPrefix), abs(pSum - maxPrefix)));
            maxPrefix = max(maxPrefix, pSum);
            minPrefix = min(minPrefix, pSum);
        }

        return result;
    }
};
