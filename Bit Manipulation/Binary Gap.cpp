class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();

        // remove leading zeros
        s = s.substr(s.find('1'));

        int i = 0, j = 0;
        int x = s.length(), maxi = 0;

        while (j < x && i < x) {
            if (s[i] == '1') {
                j = i + 1;
                while (j < x && s[j] != '1') {
                    j++;
                }
                if (j < x && s[j] == '1')
                    maxi = max(maxi, j - i);
            }
            i++;
        }
        return maxi;
    }
};
