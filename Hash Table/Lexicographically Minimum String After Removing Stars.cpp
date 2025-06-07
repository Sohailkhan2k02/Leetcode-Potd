class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        int cnt=count(s.begin(),s.end(),'*');
        if(cnt==0) return s;
        set<pair<char,int>>st;
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                s[-st.begin()->second]='*';
                st.erase(st.begin());
            }
            else{
                st.insert({s[i],-i});
            }
        }
        string res="";
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                res+=s[i];
            }
        }
        return res;
    }
};
