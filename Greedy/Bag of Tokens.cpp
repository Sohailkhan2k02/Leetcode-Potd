// T.C : O(nlogn)
// S.C : O(n)

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1;        
        while (i <= j) {            
            if (power >= tokens[i]) {
                power -= tokens[i];
                ++i;
                ++score;
            } else if (score && i != j) {
                --score;
                power += tokens[j];
                --j;
            } else
                break;              
        }
        return score;
    }
};
