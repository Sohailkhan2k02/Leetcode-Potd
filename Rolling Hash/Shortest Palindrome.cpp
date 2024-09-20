//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string lps = s + "#" + rev;
        vector<int> v(lps.size(), 0);
        for (int i = 1; i < lps.size(); i++) {
            int j = v[i - 1];
            while (j > 0 && lps[i] != lps[j]) {
                j = v[j - 1];
            }
            if (lps[i] == lps[j]) {
                v[i] = j + 1;
            }
        }
        return rev.substr(0, s.size() - v[lps.size() - 1]) + s;
    }
};
