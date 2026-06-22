class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++)
        {
            freq[text[i] - 'a']++;
        }

        int ans = min(freq[0], freq[1]);
        ans = min(ans, freq[13]);
        ans = min(ans, freq[11] / 2);
        ans = min(ans, freq[14] / 2);

        return ans;
    }
};
