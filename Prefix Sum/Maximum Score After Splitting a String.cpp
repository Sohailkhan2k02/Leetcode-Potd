//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int ans=INT_MIN;
        int zero=0,one=0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
            ans=max(ans,zero-one);
        }

        if(s[n-1]=='1'){
            one++;
        }
        return ans+one;
    }
};
