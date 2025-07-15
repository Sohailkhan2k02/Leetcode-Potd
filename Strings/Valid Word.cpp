class Solution {
public:
    bool isValid(string word) {
        bool hasVowel = false;
        bool hasConsonant = false;

        if (word.size() < 3) {
            return false;
        }

        for (char ch : word) {
            if (!isalnum(ch)) {
                return false;
            }
            if (isalpha(ch)) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
