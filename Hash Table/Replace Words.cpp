//T.C : o(n*l + m*l^2) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l)
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> st(dict.begin(), dict.end());
        stringstream ss(sentence);
        string word, res;
        
        while (ss >> word) {
            string sub = "";
            for (int i = 1; i <= word.size(); ++i) {
                sub = word.substr(0, i);
                if (st.find(sub) != st.end()) {
                    break;
                }
            }
            if (!res.empty()) res += " ";
            res += sub;
        }
        
        return res;
    }
};
