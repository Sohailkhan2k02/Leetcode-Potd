//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int n=words.size();
   vector<int> subsequenceIndices;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || groups[i] != groups[i - 1]) {
            subsequenceIndices.push_back(i);
        }
    }

    vector<string> result;
    for (int idx : subsequenceIndices) {
        result.push_back(words[idx]);
    }

    return result;
    }
};
