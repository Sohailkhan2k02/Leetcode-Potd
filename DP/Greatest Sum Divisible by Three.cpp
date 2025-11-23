class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int a = 1e9, b = 1e9;   
        int c = 1e9, d = 1e9;   

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) {
                if (x < a) { c = a; a = x; }
                else c = min(c, x);
            } else if (x % 3 == 2) {
                if (x < b) { d = b; b = x; }
                else d = min(d, x);
            }
        }

        if (sum % 3 == 0) return sum;
        if (sum % 3 == 1) return sum - min(a, b + d);
        return sum - min(b, a + c);
    }
};
