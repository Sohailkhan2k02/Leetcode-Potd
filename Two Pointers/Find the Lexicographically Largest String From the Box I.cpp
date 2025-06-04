//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word ;
        int window_sz = word.length() - numFriends + 1 ;
        string res = "" ;
        vector<vector<int>> m(26) ;
        char check = '0' ;
        for(int i = 0 ; i < word.length() ; i++){
            m[word[i]-'a'].push_back(i) ;
            if(word[i]>check) check = word[i] ;
        }
        for(auto &x : m[check-'a']){
            int j = min({x + window_sz - 1, (int)word.length()-1}) ;
            int i = x ;
            string check = word.substr(i,j-i+1) ;
            if(check > res) res = check ;
        }
        return res ;
    }
};
