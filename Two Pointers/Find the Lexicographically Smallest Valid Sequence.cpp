class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> nxtIdx(n + 1, vector<int>(26, -1));

        for(int i = n - 1; i >= 0; i--){
            nxtIdx[i] = nxtIdx[i + 1];
            nxtIdx[i][word1[i] - 'a'] = i;
        }

        vector<int> suff(m, -1);

        int k = m - 1;

        for(int i = n - 1; i >= 0 && k >= 0; i--){
            if(word1[i] == word2[k]){
                suff[k] = i;
                k--;
            }
        }

        vector<int> ans;

        int i = 0;
        int j = 0;
        bool Used = false;

        while(i < n && j < m){
            int idx = nxtIdx[i][word2[j] - 'a'];

            if(Used == true){
                if(idx == -1)
                    return {};

                if(j < m - 1 && suff[j + 1] <= idx)
                    return {};

                ans.push_back(idx);
                i = idx + 1;
                j++;
            }
            else{
                if(word1[i] == word2[j]){
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else if(j == m - 1 ||
                        (suff[j + 1] != -1 && i < suff[j + 1])){
                    Used = true;
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
        }

        if(ans.size() == m)
            return ans;

        return {};
    }
};
