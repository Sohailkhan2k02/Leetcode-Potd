//T.C : O(n+m)
//S.C : O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size(),m=goal.size();
        s+=s;
        return s.find(goal)!=string::npos && n==m;
    }
};
