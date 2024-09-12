//T.C : O(n*words[i].size())
//S.C : O(n)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mpp;
        for(auto i:allowed) mpp[i]++;
        int n=words.size();
        int cnt=0;
        
        for(int i=0; i<n; i++){
            bool f=1;
            for(int j=0; j<words[i].size(); j++){
                if(mpp.find(words[i][j])==mpp.end()){
                    f=0;
                }
            }
            if(f) cnt++;
        }
        return cnt;
    }
};
