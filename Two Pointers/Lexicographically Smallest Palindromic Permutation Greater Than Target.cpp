class Solution {
public:
    string lexPalindromicPermutation(string& s, const string& t) {
        const int n = s.size();

        int sCnt[26]{};
        for (char c : s) sCnt[c-'a']++;

        int midC = -1;
        for (int c = 0; c < 26; c++) {
            if ((sCnt[c] & 1) == 1) {
                if (midC != -1) return "";
                midC = c;
            }
        }
        if ((midC != -1) ^ ((n & 1) == 1)) return "";
        if (midC != -1) {
            s[n / 2] = 'a'+midC;
            sCnt[midC]--;
        }

        int maxC  = 25;
        int rbInd = -1;

        int ind = 0;
        while(ind < n / 2) {
            while(maxC > 0 && sCnt[maxC] == 0) maxC--;

            const char c = t[ind];

            if (maxC > c-'a') rbInd = ind;
            if (sCnt[c-'a'] == 0) break;

            s[ind] = c;
            s[n-1-ind] = c;
            sCnt[c-'a'] -= 2;
            ind++;
        }
        if (ind == n / 2) {
            // Left side matches. Is the right side smaller?
            for (int i = n / 2; i < n; i++) {
                if (s[i] > t[i])
                    return s; // yes
                else if (s[i] < t[i])
                    break;
            }
        }
        // no
        if (rbInd == -1) return "";
        ind--; // W did not spend a token at ind.

        // Recover spent tokens
        while(ind >= rbInd) {
            const char c = t[ind];

            sCnt[c-'a'] += 2;
            ind--;
        }
        ind++;

        char c = t[ind]+1;
        while(sCnt[c-'a'] == 0) c++;
        s[n-1-ind] = c;
        s[ind++] = c;
        sCnt[c-'a'] -= 2;

        char minC = 0;
        while(ind < n / 2) {
            while(sCnt[minC] == 0) minC++;
            
            sCnt[minC] -= 2;
            s[n-1-ind] = 'a'+minC;
            s[ind++] = 'a'+minC;
        }

        return s;
    }
};
