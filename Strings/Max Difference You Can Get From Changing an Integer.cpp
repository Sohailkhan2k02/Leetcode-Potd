class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;

        // Maximize: replace first digit ≠ '9' with '9'
        for (char a : s) {
            if (a != '9') {
                for (char &x : maxi)
                    if (x == a) x = '9';
                break;
            }
        }

        // Minimize:
        if (s[0] != '1') {
            char a = s[0];
            for (char &x : mini)
                if (x == a) x = '1';
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char a = s[i];
                    for (int j = 1; j < mini.size(); ++j)
                        if (mini[j] == a) mini[j] = '0';
                    break;
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
