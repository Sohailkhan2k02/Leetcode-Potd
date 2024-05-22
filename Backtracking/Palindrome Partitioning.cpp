//T.C : O(N*2^N)
//S.C : O(N*N)
class Solution {
public:
    bool isPal(int i, int j,string s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f(int ind, string s, vector<string>&ds, vector<vector<string>>&res){
        int n=s.size();
        if(ind==n){
            res.push_back(ds);
            return;
        }
        for(int i=ind; i<n; i++){
            if(isPal(ind,i,s)){
                ds.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,ds,res);
                ds.pop_back();
            }            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        f(0,s,ds,res);
        return res;
    }
};
