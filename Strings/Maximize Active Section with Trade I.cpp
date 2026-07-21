class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";
        int ones = count(s.begin(), s.end(), '1') - 2;
        vector<int> len;
        vector<char> ch;
        for (int i = 0; i < s.size();) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            ch.push_back(s[i]);
            len.push_back(j - i);
            i = j;
        }
        int ans = ones;
        for (int i = 1; i + 1 < ch.size(); i++) {
            if (ch[i] == '1' && ch[i - 1] == '0' && ch[i + 1] == '0')
                ans = max(ans, ones + len[i - 1] + len[i + 1]);
        }
        return ans;
    }
};
