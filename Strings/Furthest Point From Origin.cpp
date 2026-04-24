class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0 , countR = 0, count_ = 0;
        for(auto& m : moves){
            countL += (m == 'L');
            countR += (m == 'R');
            count_ += (m == '_');
        }
        return abs(countL - countR) + count_;
    }
};
