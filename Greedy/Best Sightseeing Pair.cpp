//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int mxScore=0,mxVal=values[0]+0;
        for(int i=1; i<n; i++){
            mxScore=max(mxScore,mxVal+values[i]-i);
            mxVal=max(mxVal,values[i]+i);
        }
        return mxScore;
    }
};
