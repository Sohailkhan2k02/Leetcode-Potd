//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int possibleStringCount(string word) 
    {
        int ans = 1, count = 0, n = word.size();
        for(int i = 1; i <= n; i++)
        {
            if(word[i] == word[i - 1]) count += 1;
            else ans += count, count = 0;
        }    
        return ans;
    }
};
