class Solution {
public:
    string toLower(string s){
       for (char& c : s) c = tolower(c);
       return s;
    }
    string normalize(string s){
        for (char& c : s){ 
            c = tolower(c);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c = '*';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lower;
        unordered_map<string, string> vowel;
        int m = wordlist.size();
        int n = queries.size();
        for (string& str : wordlist){
            exact.insert(str);
            string qlow = toLower(str);
            if(!(lower.count(qlow))) lower[qlow] = str;
            string qnorm = normalize(str);
            if (!(vowel.count(qnorm))) vowel[qnorm] = str;
        }
        vector<string> result;
        for (string& q : queries){
            if (exact.count(q)){
                result.push_back(q);
                continue;
            }
            string qlow = toLower(q);
            if (lower.count(qlow)){
                result.push_back(lower[qlow]);
                continue;
            }
            string qnorm = normalize(q);
            if (vowel.count(qnorm)){
                result.push_back(vowel[qnorm]);
                continue;
            }
            result.push_back("");  
        }
        return result; 
    }
};
