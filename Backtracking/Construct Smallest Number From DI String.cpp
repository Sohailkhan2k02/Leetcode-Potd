//T.C : O(pattern.size())
//S.C : O(pattern.size())
class Solution {
public:
    string smallestNumber(string pattern) {
        int l = pattern.size();
        string res = "123456789";
        stack<int> s;
        int d = 0;
        
        for (int i = l - 1; i >= 0; i--) {
            if (pattern[i] == 'D') d++;
            else {
                if (d) s.push(d);
                d = 0;
                s.push(0);  // for 'I'
            }
        }
        if (d) s.push(d);
        
        int i = 1;
        while (!s.empty()) {
            if (!s.top()) i++;
            else {
                reverse(res.begin() + i - 1, res.begin() + i + s.top());
                i += s.top();
            }
            s.pop();
        }

        return res.substr(0, l + 1);
    }
};
