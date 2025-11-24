class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;

        for(int bit : nums) {
            x = (x * 2 + bit) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};
