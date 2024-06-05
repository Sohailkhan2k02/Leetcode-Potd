//T.C : O(n*26)
//S.C : O(26*n)
class Solution {
public:
    void f(string &words, int cnt[26]){
        for(char ch:words){
            cnt[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        int cnt[26]={0};
        f(words[0],cnt);
        for(int i=1; i<n; i++){
            int temp[26]={0};
            f(words[i],temp);

            for(int j=0; j<26; j++){
                cnt[j]=min(cnt[j],temp[j]);
            }
        }

        vector<string>res;
        for(int i=0; i<26; i++){
            while(cnt[i]!=0){
                res.push_back(string(1,i+'a'));
                cnt[i]--;
            }
        }
        return res;

    }
};
