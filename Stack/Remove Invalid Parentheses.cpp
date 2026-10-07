class Solution {

    static bool cmp(const std::string& a, const std::string& b) {
        return a.length() != b.length() ? a.length() < b.length() : a < b;
    }

    void rec(set<string, decltype(&cmp)>& res, string curr, int ix) {

        if (curr.empty()) {
            res.insert(curr);
            return;
        }
        if (ix > curr.size())
            return;
        int c = 0;
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == ')')
                c--;
            else if (curr[i] == '(')
                c++;
            if (c < 0)
                break;
        }
        if (c == 0) {
            res.insert(curr);
        }
        for (int i = ix; i < curr.size(); i++) {
            char c1 = curr[i];
            if ((c1 != '(' && c1 != ')') || (i > ix && curr[i] == curr[i - 1]))
                continue;
            curr.erase(i, 1);
            rec(res, curr, i);
            curr.insert(i, 1, c1);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        set<string, decltype(&cmp)> res(cmp);
        string curr = s;
        int ix = 0;
        rec(res, curr, ix);
        vector<string> res1;
        int prv = -1;
        for (auto it = res.rbegin(); it != res.rend(); ++it) {
            int curr = (*it).size();
            if (prv != curr && prv != -1)
                break;
            res1.push_back(*it);
            prv = curr;
        }
        return res1;
    }
};
