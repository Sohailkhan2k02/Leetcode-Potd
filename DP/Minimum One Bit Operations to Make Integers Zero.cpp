class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int curr = 1;
        while (curr <= n) {
            if (n & curr) {
                ans = (curr * 2 - 1) - ans;
            }
            curr <<= 1;
        }      
        return ans;
    }
};
