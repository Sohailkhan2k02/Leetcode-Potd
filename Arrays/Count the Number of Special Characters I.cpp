class Solution {
public:
    int numberOfSpecialChars(string w) {
        int x=0; set<char>a,b;
        for(char c:w) islower(c)?a.insert(c):b.insert(c+32);
        for(char c:a) x+=b.count(c);
        return x;
    }
};
