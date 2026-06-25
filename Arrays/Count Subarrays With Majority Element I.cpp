class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int balance = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int res = 0;
        int curr = 0;
        for (int x : nums) {
            if (x == target) {
                curr += cnt[balance];
                balance++;
            } else {
                balance--;
                curr -= cnt[balance];
            }
            cnt[balance]++;
            res += curr;
        }
        return res;
    }
};
