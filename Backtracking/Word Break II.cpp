//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    void f(int ind, string s, map<string,int>&mpp, vector<string>&ds,vector<string>&res){
        int n=s.size();
        if(ind==n){
            string temp="";
            for(int i=0; i<ds.size(); i++){
                temp+=ds[i];
                if(i<ds.size()-1){
                    temp+=" ";
                }
            }
            res.push_back(temp);
            return;
        }
        for(int i=ind; i<n; i++){
            string sub=s.substr(ind,i-ind+1);
            if(mpp.find(sub)!=mpp.end()){
                ds.push_back(sub);
                f(i+1,s,mpp,ds,res);
                ds.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        int n=word.size();
        map<string,int>mpp;
        for(auto i:word){
            mpp[i]++;
        }
        vector<string>ds;
        vector<string>res;
        f(0,s,mpp,ds,res);
        return res;
    }
};



//Approach-2 (Using simple backtracking)
//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string &s) {
       if(s.empty()) {
            return {""};
       }
      
       if(mp.count(s))
            return mp[s];

        if(mp.count(s))
            return mp[s];
        
        vector<string> result;
        for(int l = 1; l <= s.length(); l++) {
            string currWord   = s.substr(0, l);
            if(dict.count(currWord)) {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord);
                for(string &w : remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }


        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        return solve(s);
    }
};//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string& currSentence, string &s) {
        if(i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.length(); j++) {

            string tempWord = s.substr(i, j-i+1);

            if(dict.find(tempWord) != dict.end()) {
                string origSentence = currSentence;
                if(!currSentence.empty())
                    currSentence += " ";
                
                currSentence += tempWord;

                solve(j+1, currSentence, s);

                currSentence = origSentence;

            }

        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        string currSentence = "";
        solve(0, currSentence, s);

        return result;
    }
};



//Approach-2 (Using simple backtracking)
//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string &s) {
       if(s.empty()) {
            return {""};
       }
      
       if(mp.count(s))
            return mp[s];

        if(mp.count(s))
            return mp[s];
        
        vector<string> result;
        for(int l = 1; l <= s.length(); l++) {
            string currWord   = s.substr(0, l);
            if(dict.count(currWord)) {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord);
                for(string &w : remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }


        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        return solve(s);
    }
};
