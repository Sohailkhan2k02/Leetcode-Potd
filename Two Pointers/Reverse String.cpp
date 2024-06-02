//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            swap(s[i++],s[j--]);
        }
    }
};
