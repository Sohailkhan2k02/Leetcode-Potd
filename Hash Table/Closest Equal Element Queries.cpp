class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> temp(n, n);

        unordered_map<int, int> mpp;

        for (int i = 0; i < 2 * n; i++) {
            int ind = i % n;      
            int num = nums[ind];  
            if (mpp.find(num) != mpp.end()) {
                int prev = mpp[num] % n;

                int d = i - mpp[num];  
                temp[ind] = min(temp[ind], d);
                temp[prev] = min(temp[prev], d);
            }

            mpp[num] = i;
        }

        vector<int> ans;
        for (int query : queries) {
            if (temp[query] == n)
                ans.push_back(-1);
            else
                ans.push_back(temp[query]);
        }

        return ans;
    }
};
