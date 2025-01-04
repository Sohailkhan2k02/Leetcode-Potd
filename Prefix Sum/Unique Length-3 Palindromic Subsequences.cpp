//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<pair<int,int>>vec(26,{-1,-1});

        for(int i=0; i<n; i++){
            char ch=s[i];
            int ind=ch-'a';

            if(vec[ind].first==-1){
                vec[ind].first=i;
            }
            vec[ind].second=i;
        }

        int res=0;
        for(int i=0; i<26; i++){
           int left=vec[i].first;
           int right=vec[i].second;

           if(left==-1) continue;

           unordered_set<char>st;

           for(int i=left+1; i<=right-1; i++){
               st.insert(s[i]);
           }
           res+=st.size();
        }

        return res;
    }
};
