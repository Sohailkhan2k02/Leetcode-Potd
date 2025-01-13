//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int cnt=n;
      map<char,int>mpp;
     for(int i=0;i<n;i++){
        mpp[s[i]]++;
        if(mpp[s[i]]>2){
            mpp[s[i]]=1;
            cnt-=2;
        }
     }
     return cnt;

    }
};
