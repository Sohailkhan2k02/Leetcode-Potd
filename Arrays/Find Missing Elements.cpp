class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<bool> present(101, false);

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i : nums) {
            present[i] = true;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        vector<int> ans;

        for (int i = mini; i <= maxi; i++) {
            if (!present[i])
                ans.push_back(i);
        }

        return ans;
    }
};
