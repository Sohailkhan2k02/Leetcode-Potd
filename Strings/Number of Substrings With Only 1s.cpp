class Solution {
public:
    int numSub(string s) {
        const int mod=1e9+7;
        int n=s.size();
        int len=0,res=0;
        for(int i=0; i<n; i++){
          if(s[i]=='1'){
              len+=1;
              res=(res+len)%mod;
          }
          else
          len=0;
        }
          return res;
    }
};
