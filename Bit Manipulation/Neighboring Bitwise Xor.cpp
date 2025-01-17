//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for (auto val : derived) {
            xr ^= val;
        }
        return xr == 0;
    }
};
