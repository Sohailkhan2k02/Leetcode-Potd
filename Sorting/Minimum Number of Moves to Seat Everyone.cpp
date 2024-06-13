//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:
    int minMovesToSeat(vector<int>& s1, vector<int>& s2) {
        sort(s1.begin(),s1.end()); sort(s2.begin(),s2.end());
        int diff=0;
        for(int i=0; i<s1.size(); i++){
            diff+=abs(s1[i]-s2[i]);
        }
        return diff;
    }
};
