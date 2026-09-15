class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        const int n = s.size();
        int count = 0;

        for (int i = 0; i <= n - k; i++) {
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k - 1;
            }
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k;
            }
        }

        return count;
    }
};
