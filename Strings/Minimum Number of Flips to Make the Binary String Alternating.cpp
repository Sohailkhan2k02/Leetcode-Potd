class Solution {
public:

    int minFlips(string s) {
        string str = s + s;
        int n = s.length();
        int ans = INT_MAX;

        int i = 0, j = n - 1;

        while (j < str.length()) {
            string sub = str.substr(i, j - i + 1);
            ans = min(ans, minOperations(sub));
            i++;
            j++;
        }

        return ans;
    }

    int minOperations(string s) {
        return min(check(s, true), check(s, false));
    }

    int check(string s, bool flag) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {

            if(flag) {
                if(s[i] != '1') count++;
            }
            else {
                if(s[i] != '0') count++;
            }

            flag = !flag;
        }

        return count;
    }
};
