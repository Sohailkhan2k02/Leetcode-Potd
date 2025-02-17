//T.C : O(26)
//S.C : O(26)
class Solution {
private:
    int buildstring(vector<int>&freq){
        int ways = 0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                freq[i]--;
                ways += 1 + buildstring(freq);
                freq[i]++;
            }
        }
        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char c:tiles){
            freq[c-'A']++;
        }
        return buildstring(freq);
    }
};
