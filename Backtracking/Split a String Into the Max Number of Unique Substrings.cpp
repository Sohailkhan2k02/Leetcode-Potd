//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
    int maxi=-1;
    void f(int ind, string s, unordered_set<string>&st,vector<string>&res){
        int n=s.size();
        if(ind==n){
            maxi=max(maxi,(int)st.size());
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(st.find(s.substr(ind,i-ind+1))!=st.end()) continue;
            st.insert(s.substr(ind,i-ind+1));
            f(i+1,s,st,res);
            st.erase(s.substr(ind,i-ind+1));
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        vector<string>res;
        f(0,s,st,res);
        return maxi;
    }
};
