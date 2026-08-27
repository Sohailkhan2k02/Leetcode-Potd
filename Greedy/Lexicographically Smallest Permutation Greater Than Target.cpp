class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int>cnt(26);
        for(char c : s){
            cnt[c - 'a']++;
        }
        for(char  c : target){
            cnt[c-'a']--;
        }
        int n = s.size();
        for(int i=n-1 ; i >= 0 ;i--){
            char c = target[i];
            int pos = c - 'a';
            cnt[c-'a']++;
            bool ok = true;
            for(int j = 0 ; j < 26; j++){
                if(cnt[j] < 0)ok = false;
            }
            if(!ok)continue;
            string ans = target.substr(0,i);
            int next;
            bool possible = false;
            for(int j = pos+1 ; j < 26; j++){
                if(cnt[j] > 0){
                    next = j;
                    possible = true;
                    break;
                }
            }
            if(!possible)continue;
            ans.push_back('a' + next);
             cnt[next]--;
            for(int j = 0; j < 26; j++){
                ans.append(cnt[j],'a' + j);
            }
            return ans;
        }
        return "";
    }
};
