//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size();
        int i=0;
        int k=0;
        string res="";
        while(i<n){
            if(k<spaces.size() && i==spaces[k]){
                res+=' ';
                k++;
            }
            res+=s[i];
            i++;
        }
        return res;
    }
};
