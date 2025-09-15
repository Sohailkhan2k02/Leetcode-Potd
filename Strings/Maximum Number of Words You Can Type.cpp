class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int count = 0;
        bool hasBroken = false;
        for(int i=0; i<=text.size(); i++){
            
            
            if(i == text.size() || text[i] == ' ')
            {
                if (!hasBroken) count++;
                hasBroken = false; // reset for next word
            }
            else if(broken.count(text[i]))
            hasBroken = true; 
        }

        return count;
    }
};
