class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mindist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forwddist = abs(i - startIndex);
                int backdist = n - forwddist;
                mindist = min(mindist, min(forwddist, backdist));
            }
        }

        return mindist == INT_MAX ? -1 : mindist;
    }
};
