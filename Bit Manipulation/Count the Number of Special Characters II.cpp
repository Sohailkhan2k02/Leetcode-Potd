class Solution {
public:
    int f(string s) {
        unordered_map<char, int> mpp;
        int cnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (islower(c) && mpp.find(c) == mpp.end()) {
                mpp[c] = i;
            } else if (isupper(c)) {
                char lw = tolower(c);
                auto it = mpp.find(lw);
                if (it != mpp.end() && it->second <= i) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
    int numberOfSpecialChars(string s) {
        unordered_map<char, int> qtr, ptr;
        for (int i = 0; i < s.size(); i++) {
            char c = tolower(s[i]);
            if (islower(s[i])) {
                qtr[c] = i;
            } else {
                if (ptr.find(c) == ptr.end()) {
                    ptr[c] = i;
                }
            }
        }
        int cnt = 0;
        for (auto &p : qtr) {
            if (ptr.find(p.first) != ptr.end() && p.second < ptr[p.first]) {
                cnt++;
            }
        }
        return cnt;
    }
};
