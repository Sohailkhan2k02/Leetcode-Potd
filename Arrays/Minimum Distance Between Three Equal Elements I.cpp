class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto& p : mp)
        {
            vector<int> &idx = p.second;
            if(idx.size() < 3)
            continue;

            for(int i = 0; i+2 < idx.size(); i++)
            {
                int distance = 2 * (idx[i+2] - idx[i]);
                ans = min(ans, distance);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
