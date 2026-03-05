class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int cnt;
        for(int i=0;i<s.length();i++) {
            if(s[i]-'0'==i%2) {
                cnt++;
            }
        }
        int ctn=n-cnt;
        return min(cnt,ctn);
    }
};
