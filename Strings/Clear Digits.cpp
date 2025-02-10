//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        string res="";
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
