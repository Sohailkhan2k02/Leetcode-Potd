class Solution {
public:
    int countCommas(int n) {
        int totalCommas = 0;
        long long base = 1000;
        
        while (n >= base) {
            totalCommas += (n - base + 1);
            base *= 1000;
        }
        
        return totalCommas;
    }
};
