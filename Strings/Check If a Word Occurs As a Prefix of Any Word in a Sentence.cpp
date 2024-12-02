//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int isPrefixOfWord(string& sentence, string& searchWord) {
        string s=" "+sentence, t=" "+searchWord;
        int n=s.size();
        int m=s.find(t);
        if (m==-1) return -1;
        return 1+count(s.begin(), s.begin()+m, ' ');
    }
};
