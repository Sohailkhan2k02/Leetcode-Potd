//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(!st.empty() && (s[st.top()]=='A' && s[i]=='B' || s[st.top()]=='C' && s[i]=='D')){
                st.pop();
            }
            else st.push(i);
        }

        return int(st.size());
    }
};
