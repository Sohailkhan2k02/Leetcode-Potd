//T.C : O(2*n)
//S.C: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n=s.size();
        int i=0,j=0;
        int len=0;
        int currcost=0;
        while(j<n){
            currcost+=abs(s[j]-t[j]);
            while(currcost>cost){
                currcost-=abs(s[i]-t[i]);
                i++;
            }

            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};
