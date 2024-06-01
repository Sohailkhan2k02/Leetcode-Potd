//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0; i<n-1; i++){
            sum+=abs(s[i]-s[i+1]);
        }
        return sum;
    }
};
