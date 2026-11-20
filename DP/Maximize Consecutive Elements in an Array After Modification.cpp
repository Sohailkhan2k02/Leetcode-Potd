class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int px = -10, c = 0, a = 0, b = 0, ans = 1;
        for (int x : nums) {
            int nc, na, nb;
            if (x == px)          { nc = c; na = c + 1; nb = a + 1; }
            else if (x == px + 1) { nc = a; na = a + 1; nb = b + 1; }
            else if (x == px + 2) { nc = b; na = b + 1; nb = 1; }
            else                  { nc = 0; na = 1;     nb = 1; }
            px = x; c = nc; a = na; b = nb;
            ans = max(ans, max(a, b));
        }
        return ans;
    }
};
