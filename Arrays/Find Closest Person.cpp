class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1 = abs(z - x);
        int p2 = abs(z - y);
        if (p2 > p1) return 1;     // Person 1 closer
        else if (p1 > p2) return 2; // Person 2 closer
        else return 0;              // Both same distance
    }
};
