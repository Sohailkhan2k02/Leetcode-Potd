class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> fvis(n, 0);
        vector<int> bvis(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= fruits[i] && (!bvis[j])) {
                    fvis[i] = 1;
                    bvis[j] = 1;
                    break;
                }
            }
        }
        int count = 0;
        for (auto vis : fvis) {
            if (!vis)
                count++;
        }

        return count;
    }
};
