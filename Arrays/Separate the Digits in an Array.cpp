class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            string s = to_string(num);

            for (char digit : s) {
                ans.push_back(digit - '0');
            }
        }

        return ans;
    }
};
