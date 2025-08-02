class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> imba;
        int minCost = INT_MAX;
        for (int i = 0; i < basket1.size(); ++i)
        {
            imba[basket1[i]]++;
            imba[basket2[i]]--;
            minCost = min({minCost, basket1[i], basket2[i]});
        }
        vector<int> swaps;
        for (auto& [fruit, diff] : imba)
        {
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < abs(diff)/2; ++i)
            {
                swaps.push_back(fruit);
            }
        }
        sort(swaps.begin(), swaps.end());
        long long result = 0;
        for (int i = 0; i < swaps.size()/2; ++i)
        {
            result += min({minCost*2, swaps[i]});
        }
        return result;
    }
};
