class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
      unordered_map<int, int> mpp;
    vector<int> res;

    for (int i : nums) {
        mpp[i]++;
    }

    for (auto& i : mpp) {
        if (i.second == 2) {
            res.push_back(i.first);
        }
    }

    return res;
    }
};
