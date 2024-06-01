//T.C : O(n)
//S.C : O(1)
#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll n = nums.size();
        ll xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
        }

        ll rightmostbit = xr & (xr - 1) ^ xr;
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < n; i++) {
            if (rightmostbit & nums[i]) {
                s1 ^= nums[i];
            } else {
                s2 ^= nums[i];
            }
        }
        return {(int)s1, (int)s2};
    }
};
