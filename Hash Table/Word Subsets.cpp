//T.C : O(n*26)
//S.C : O(26)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freqB[26] = {};
        for(const auto &w : words2){
            int temp[26] = {};
            for(char c : w) temp[c - 'a']++;
            for(int i=0; i<26; i++){
                if(temp[i] > freqB[i]) freqB[i] = temp[i];
            }
        }
        vector<string> ans;
        ans.reserve(words1.size());
        for(auto &w : words1){
            int freq[26] = {};
            for(char c : w) freq[c - 'a']++;
            bool ok = true;
            for(int i=0; i<26; i++){
                if(freq[i] < freqB[i]){
                    ok = false;
                    break;
                }
            }
            if(ok) ans.push_back(w);
        }
        return ans;
    }
};
