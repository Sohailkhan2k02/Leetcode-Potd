class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        for(int i = 0; i < s.length(); i++)
        {
            if(flag)
            {
                if(s[i] == 'a') continue;
                else flag = false;
            }
            else
            {
                if(s[i] == 'a') return false;
            }
        }
        return true;
    }
};
