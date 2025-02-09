//T.C : O(n)
//S.C : O(n)
#define ll long long

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long, int> mp;
        ll s = nums.size();
        
        for (long i = 0; i < s; i++) {
            mp[nums[i] - i]++;
        }
        
        ll goodPairs = 0;
        for (auto &i : mp) {
            ll n = i.second;
            goodPairs += (n - 1) * n / 2; // Count good pairs
        }
        
        return s * (s - 1) / 2 - goodPairs; // Total pairs - good pairs
    }
};
