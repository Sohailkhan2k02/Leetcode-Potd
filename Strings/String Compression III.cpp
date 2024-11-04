//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        int cnt=1;
        int i=0,j=0;
        string res="";
        while(j<n){
            while(j<n && s[j]==s[j+1] && cnt<9){
                cnt++;
                j++;
            }
            res+=to_string(cnt);
            res+=s[i];
            i=j+1;
            cnt=1;
            j++;
        }
        return res;
    }
};
