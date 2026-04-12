class Solution {
public:
    int memo[300][27][27];
    int dist(int from, int to){
        if(from ==26){
            return 0;
        }
        int x1 = from /6;
        int y1 = from %6;
        int x2=to/6;
        int y2 = to%6;
        return abs(x1-x2)+abs(y1-y2);
    }
    int help(int idx, int f1, int f2, string word){
        if(idx == word.size()){
            return 0;
        }
        if(memo[idx][f1][f2] != -1){
            return memo[idx][f1][f2];
        }
        int curr = word[idx]-'A';
        int d1 = dist(f1, curr) + help(idx+1, curr, f2, word);
        int d2 = dist(f2, curr)+help(idx+1, f1, curr, word);
        return memo[idx][f1][f2] = min(d1, d2);
    }
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return help(0, 26, 26, word);
    }
};
