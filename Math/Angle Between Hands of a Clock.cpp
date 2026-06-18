class Solution {
public:
    double angleClock(int hour, int minutes) {

        double angle = abs((30.0 * hour) - (5.5 * minutes));

        return min(angle, 360.0 - angle);
    }
};
