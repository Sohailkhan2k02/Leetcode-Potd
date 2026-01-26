class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(size_t i = 1; i < arr.size(); ++i)
            diff = min(diff, arr[i] - arr[i-1]);

        vector<int> tmp(2,0);
        vector<vector<int>> ret{};
        for(size_t i = 1; i < arr.size(); ++i)
        {
            if(arr[i] - arr[i-1] == diff)
            {
                tmp[0] = arr[i-1];
                tmp[1] = arr[i];
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
