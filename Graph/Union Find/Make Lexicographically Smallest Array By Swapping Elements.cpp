//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> idxVals;
        for (int i = 0; i < nums.size(); ++i) 
            idxVals.push_back({nums[i], i});
        
        sort(idxVals.begin(), idxVals.end());

        vector<vector<int>> groups = {{idxVals[0].second}};
        for (int i = 1; i < nums.size(); ++i) {
            if (idxVals[i].first - idxVals[i - 1].first <= limit)
                groups.back().push_back(idxVals[i].second);
            else
                groups.push_back({idxVals[i].second});
        }

        for (auto& grp : groups) {
            vector<int> vals;
            for (int idx : grp) vals.push_back(nums[idx]);
            sort(vals.begin(), vals.end());
            sort(grp.begin(), grp.end());
            for (int j = 0; j < grp.size(); ++j) nums[grp[j]] = vals[j];
        }
        return nums;
    }
};
