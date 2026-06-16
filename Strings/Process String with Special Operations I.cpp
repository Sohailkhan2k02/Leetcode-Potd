class Solution {
public:
    static string processStr(string& s) {
        string t;
        for(char c: s){
            switch(c){
                case '*': 
                    if (!t.empty()) t.pop_back(); 
                    break;
                case '#':
                    t.append(t.begin(), t.end());  
                    break; 
                case '%':
                    reverse(t.begin(), t.end());
                    break;
                default: t.push_back(c);
            }
        }
        return t;
    }
};
