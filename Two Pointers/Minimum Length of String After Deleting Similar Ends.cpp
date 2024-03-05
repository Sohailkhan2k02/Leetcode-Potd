// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<=j && s[i]==ch){
                i++;
            }
            while(i<=j && s[j]==ch){
                j--;
            }
        }

        return max(0, j-i+1);
    }
};
