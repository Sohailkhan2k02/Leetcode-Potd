//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size(),m=t.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        cout<<j<<" ";
        return m-j;
    }
};
