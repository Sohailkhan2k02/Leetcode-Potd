//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int res = 0;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;
            res += count[key];
            count[key]++;
        }
        return res;
    }
};
