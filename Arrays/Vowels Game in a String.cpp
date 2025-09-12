class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }

    bool doesAliceWin(string s) {
        int n=s.size();
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                return true;
            }
        }
        return false;
    }
};
