class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int x1 = 0, x2 = 0;
    for (int num : nums) {
        if (num % 3 == 1) {
            x1++;
        } else if (num % 3 == 2) {
            x2++;
        }
    }
    return x1+x2;
    }
};
