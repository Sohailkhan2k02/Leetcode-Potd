//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mpp;
        stringstream ss(s1),ss1(s2);
        string token="",token2="";
        while(ss>>token){
            mpp[token]++;
        }
        while(ss1>>token2){
            mpp[token2]++;
        }
        vector<string>res;
        for(auto [u,f]:mpp){
            if(f==1){
                res.push_back(u);
            }
        }
        return res;
    }
};
