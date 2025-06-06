//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minChartoRight(n);
        minChartoRight[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            minChartoRight[i] = min(s[i], minChartoRight[i+1]);
        }
        string t = "", p = "";
        for(int i=0; i<n; i++){
            t += s[i];
            char minChar  = (i+1 < n) ? minChartoRight[i+1] : s[i];
            while(!t.empty() && t.back() <= minChar){
                p += t.back();
                t.pop_back();
            }
        }
        while(!t.empty()){
            p += t.back();
            t.pop_back();
        }
        return p;
    }
};
