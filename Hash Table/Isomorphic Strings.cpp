//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(),m=t.size();
        // unordered_map<char,char>mpp1,mpp2;
        char mpp1[256]={0},mpp2[256]={0};
        for(int i=0; i<n; i++){
            mpp1[s[i]]=t[i];
            mpp2[t[i]]=s[i];
        }

        for(int i=0; i<n; i++){
            if(mpp1[s[i]]!=t[i] || mpp2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};
