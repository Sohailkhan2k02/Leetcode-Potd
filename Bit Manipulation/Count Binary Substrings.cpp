class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> groups;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                count++;
            }
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        int ans = 0;
        for (int i = 1; i < groups.size(); i++) {
            ans += min(groups[i], groups[i-1]);
        }
        return ans;
    }
};
