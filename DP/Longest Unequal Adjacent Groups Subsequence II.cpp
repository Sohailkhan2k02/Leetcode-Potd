//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    static bool hamming1(const string& s, const string& t){
        const int sz=s.size();
        if (sz!=t.size()) return 0;
        int diff=0;
        for (int i=0; i<sz && diff<2; i++)
            diff+=s[i]!=t[i];
        return diff==1;
    }

    static vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n=words.size();
        int maxLen=0, pos=-1;
        vector<int> dp(n, 1), next(n, -1);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(groups[i]!=groups[j] && hamming1(words[i], words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    next[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                pos=i;
            }
        }
        vector<string> ans;
        for(; pos!=-1; pos=next[pos]){
            ans.push_back(words[pos]);
        }
        return ans;
    }
};
