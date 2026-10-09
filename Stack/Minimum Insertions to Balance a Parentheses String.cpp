class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        stack<char> stck;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stck.push('(');
            else if (i < n - 1 && s[i] == s[i + 1]) {
                if (!stck.empty()) {
                    stck.pop();
                    i++;
                } else {
                    res++;
                    i++;
                }
            } else if (s[i] == ')') {
                if (stck.empty()) {
                    res += 2;
                } else {
                    res++;
                    stck.pop();
                }
            }
        }
        if (!stck.empty()) {
            res += stck.size() * 2;
        }
        return res;
    }
};
