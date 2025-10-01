class Solution {
public:
    int numWaterBottles(int n1, int n2) {
        return n1+(n1-1)/(n2-1);
    }
};
