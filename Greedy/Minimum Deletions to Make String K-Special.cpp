//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> c(26, 0);
        for (char x: word) {
            c[x - 'a'] += 1;
        }
        sort(c.begin(), c.end());
        int res = word.size();
        for (int i = 0, sum = 0; i < 26; i++) {
            if (c[i] == 0) {
                continue;
            }
            
            int tot = sum;
            for (int j = i + 1; j < 26; j++) {
                tot += max(0, c[j] - c[i] - k);
            }
            res = min(res, tot);
            
            sum += c[i];
        }
        
        return res;

    }
};
