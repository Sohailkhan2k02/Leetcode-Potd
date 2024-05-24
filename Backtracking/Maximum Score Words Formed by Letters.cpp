//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
    int maxi;
    void f(int i, vector<string>&word, vector<int>&mpp, vector<int>&score, int currScore){
        int n=word.size();
        maxi=max(maxi,currScore);
        if(i>=n){
            return;
        }

        int j=0;
        int tempScore=0;
        vector<int>tempMpp=mpp;
        while(j<word[i].size()){
            char c=word[i][j];
            tempMpp[c-'a']--;
            tempScore+=score[c-'a'];

            if(tempMpp[c-'a']<0){
                break;
            }
            j++;
        }
        if(j==word[i].size()){
            // Take
            f(i+1,word,tempMpp,score,currScore+tempScore);
        }

        // Nottake
        f(i+1,word,mpp,score,currScore);
    }
    int maxScoreWords(vector<string>& word, vector<char>& letters, vector<int>& score) {
        int n=word.size();
        maxi=INT_MIN;
        vector<int>mpp(26,0);
        for(char c:letters){
            mpp[c-'a']++;
        }

        f(0,word,mpp,score,0);
        return maxi;

    }
};
