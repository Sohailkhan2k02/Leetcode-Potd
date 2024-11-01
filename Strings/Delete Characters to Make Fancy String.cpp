//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string res="";
        int cnt=1;
        for(int i=0; i<n; i++){
            if(s[i]==s[i+1]) cnt++;
            else cnt=1;
            if(cnt<3){
                res+=s[i];
            }
        }
        return res;
    }
};
